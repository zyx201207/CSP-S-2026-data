#include<bits/stdc++.h>
using namespace std;


long long Dq[1000040][2],pfro=500020,pbac=500021;
void pushf(long long x,long long y)
{
	Dq[pfro][0]=x,Dq[pfro][1]=y;
	pfro--;
	return;
}
void pushb(long long x,long long y)
{
	Dq[pbac][0]=x,Dq[pbac][1]=y;
	pbac++;
	return;
}
void popf(){
	pfro++;
	return;
}
void popb(){
	pbac--;
	return;
}
long long frn(long long t){
	return Dq[pfro+1][t];
}
long long bak(long long t){
	return Dq[pbac-1][t];
}
long long siz(){
	return pbac-pfro-1;
}
void New_(long long x,long long num)
{
	while(siz()>0 && x>bak(0)) popb();
	pushb(x,num);
//	cout<<pfro<<" "<<frn(0)<<endl;
	return;
}


long long n,m,energ[500010],sum,ans;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int I=0;I<n;I++) cin>>energ[I];
	sort(energ,energ+n);
	long long p1=0,p2=0;
	sum=energ[0];
	while(p2<n)
	{
		New_(energ[p2],p2);
//		cout<<frn(0)<<" "<<p1<<" "<<p2<<" "<<sum<<endl;
		if((p2-p1+1)*frn(0)-sum<=m) {
			ans=max(ans,p2-p1+1);
			p2++;
			sum+=energ[p2];
//			cout<<"upd: "<<ans<<endl;
		}
		else
		{
			sum-=energ[p1];
			p1++;
			while(siz()>0 && frn(1)<p1) popf();
		}
	}
	cout<<ans;
	
	return 0;
}
