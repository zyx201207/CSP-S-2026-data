#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
long long n,m,a[500010],c[500010],ans,sum,sp,l;
long long b[500010];
map<long long,long long>mb;
bool f,f2;
//void solve1(){
//	for(int i=2;i<=n;i++){
//		sum+=c[i]*(i-1);
//		if(sum<=m)ans=i;
//		else break;
//	}
//	cout<<ans;
//}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		//if(a[i]+100000>=0&&a[i]+100000<=200005)b[a[i]+100000]++;
		mb[a[i]]++;
		//cout<<"[+]输入成功\n"; 
		//c[i]=a[i]-a[i-1];
	}
	sort(a+1,a+1+n);
	//cout<<"[+]排序成功\n"; 
	for(int i=1;i<=n;i++){
		c[i]=a[i]-a[i-1];
		if(i>1){
			if(c[i]!=c[i-1]){
				f=1;
			}
		} 
	}
//	if(!f){
//		//cout<<"[+]solve1\n"; 
//		solve1();
//		return 0;
//	}
//	if(f2){
//		//cout<<"[-]cannot solve'\n"; 
//		return 0;
//	}
	//cout<<"[+]solve0\n"; 
/*//桶排解 
	for(int i=0;i<=200005;i++){
		if(b[i]==0)continue;
		sum=b[i],sp=0;
		for(int j=1;j<=m;j++){
			if(i-j<1||b[i-j]==0)continue;
			int va=min(j*b[i-j],m-sp);
			sp+=va;
			sum+=va/j;
			if(sp==m)break;
		}
		ans=max(ans,sum);
	}
	cout<<ans;
*/ 
	for(auto it:mb){
		b[++l]=it.fi;
		sum=it.se,sp=0;
		//cout<<"[=]sum="<<sum<<" 值="<<it.fi<<endl;
		for(int i=1;;i++){
			if(l-i<1)break;
			long long j=b[l-i],va=min(mb[j]*(it.fi-j),m-sp);
			if(it.fi-j>m)continue;
			sp+=va;
			sum+=va/(it.fi-j);
			//cout<<"[+]转移来"<<va/(it.fi-j)<<"个"<<j<<" sum="<<sum<<" sp="<<sp<<endl;
			if(sp==m)break;
		}
		ans=max(ans,sum);
	}
	cout<<ans;
	return 0;
}
//5 8 -3 -1 2 2 7
//5 5 1 2 4 8 9