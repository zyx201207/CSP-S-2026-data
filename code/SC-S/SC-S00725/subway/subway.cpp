#include<bits/stdc++.h>
using namespace std;
long long read()
{
	long long f=1,num=0;
	char ch=getchar();
	while((ch>='0'&&ch<='9')||ch=='-')
	{
		if(ch=='-')f=-1;
		else{
			num*=10;
			num+=(ch-'0');
		}
		ch=getchar();
	}
	return num*f;
}
long long c,n,m,d,q,w[100005],leng[505],vis[100005],
dd[505],str[505],ed[505],uq[505],km,us[505],olp,klp;
long long f[1005][1005];
bool visc[100005],cnu[505];
struct node{
	long long id,num;
}rlw[500005];
bool cmp(const node x,const node y){
		return x.num<y.num;
}
vector<long long>uop[500005];
long long ques(long long s,long long z)
{
	if(m<=1000)if(f[s][z])return f[s][z];
//	memset(vis+1,vis+int(m)+1,0x3f3f3f3f3f);
	olp=0;
	klp=1;
	for(int i=1;i<=m;i++)visc[i]=0;
	for(int i=1;i<=n;i++)dd[i]=str[i],cnu[i]=0; 
	visc[s]=1;
	vis[s]=0;
	for(int i=0;i<uop[s].size();i++){
		cnu[uop[s][i]]=1,us[++olp]=uop[s][i];
		for(int j=str[uop[s][i]];j<=ed[uop[s][i]];j++)
		{
			if(rlw[j].id==s){
				uq[uop[s][i]]=rlw[j].num;
				break;
			}
		}
	}
	while(klp<=m)
	{
		long long mns=1145141919810,mnid=0;
		for(int i=1;i<=olp;i++){
			while(visc[rlw[dd[us[i]]].id]&&dd[us[i]]<=ed[us[i]])dd[us[i]]++;
			if(dd[us[i]]<=ed[us[i]]&&mns>rlw[dd[us[i]]].num+uq[us[i]])mns=rlw[dd[us[i]]].num+uq[us[i]],mnid=rlw[dd[us[i]]].id;
		}
		visc[mnid]=1;
		vis[mnid]=mns;
		for(int i=0;i<uop[mnid].size();i++){
			if(!cnu[uop[mnid][i]]){
				us[++olp]=uop[mnid][i];
				cnu[uop[mnid][i]]=1;
				for(int j=str[uop[mnid][i]];j<=ed[uop[mnid][i]];j++)
				if(rlw[j].id==mnid)
				{
					uq[uop[mnid][i]]=rlw[j].num+mns;
					break; 
				}
			}
		}
		klp++;
	}
	if(m<=1000)
	{
		for(int i=1;i<=m;i++)if(visc[i])f[s][i]=vis[i];
	}
	return vis[z];
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
//	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;i++)
//		scanf("%lld",&w[i]);
		w[i]=read();
	for(int i=1;i<=n;i++)
	{
		long long pl=km;
//		scanf("%lld",&leng[i]);
		leng[i]=read();
		for(int j=1;j<=leng[i];j++)
		{
			long long x,t;
//			scanf("%lld%lld",&x,&t);
			x=read(),t=read();
			rlw[++km].id=x;
			rlw[km].num=t;
			uop[x].push_back(i);
		}
		sort(rlw+pl+1,rlw+km+1,cmp);
		str[i]=pl+1;
		ed[i]=km;
	}
//	for(int i=1;i<=km;i++)cout<<rlw[i].id<<" "<<rlw[i].num<<endl;
	for(int Q=1;Q<=q;Q++)
	{
		long long s,z;
		scanf("%lld%lld",&s,&z);
		printf("%lld\n",ques(s,z)+w[s]+w[z]);
	}
	return 0;
}
/*0 2 5 20 2 
4 1 9 2 5 
3 1 5 2 7 4 6 
3 2 3 3 4 5 7 
1 3 
1 2 
*/