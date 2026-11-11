#include<bits/stdc++.h>
#define maxn 500005
#define maxm 1000000000000000000ull
typedef long long llong;
typedef unsigned long long ulong;
using namespace std;
int n;
int a[maxn],b[maxn];
ulong m;
llong qzh[maxn];
inline bool chk(int x){
	return qzh[x]<=m;
}
map<int,int>mp;
int erfen(){
	int l=0,r=n;
	while(l<=r){
		int mid=l+((r-l)>>1);
		if(chk(mid)){
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	return l;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	qzh[0]=0;
	scanf("%d %ull",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(mp.find(a[i])!=mp.end())
			mp[a[i]]++;
		else mp[a[i]]=1;
	}
	if(n==1){
		printf("1");
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++){
		b[i]=a[i+1]-a[i];
		qzh[i]=qzh[i-1]+b[i]*i;
	}
	int ans=upper_bound(qzh+1,qzh+n,m)-qzh;
	int jie=a[ans+1]-a[ans];
	int sheng=m-qzh[ans-1];
	//printf("%d,%d,%d,%d\n",jie,mp[a[ans+1]],mp[a[ans]]+(m/jie)-qzh[ans],mp[a[ans]]);
	printf("%d",max(ans-mp[a[ans]]+(mp[a[ans+1]]+mp[a[ans]]+(m/jie)-qzh[ans]),(ulong)ans));
	fclose(stdin);
	fclose(stdout);
	return 0;
}/*#include<bits/stdc++.h>
#define maxn 500005
#define maxm 1000000000000000000ull
typedef long long llong;
typedef unsigned long long ulong;
using namespace std;
int n;
int a[maxn],b[maxn];
ulong m;
llong qzh[maxn];
inline bool chk(int x){
	return qzh[x]<=m;
}
map<int,int>mp;
int erfen(){
	//cout<<"Live\n";
	int l=0,r=n;
	while(l<=r){
		//cout<<"Live\n";
		int mid=l+((r-l)>>1);
		//cout<<"Live\n";
		if(chk(mid)){
			//printf("%d Can!\n",mid);
			l=mid+1;
		}else{
			//printf("%d Cannot!\n",mid);
			r=mid-1;
		}
	}
	return l;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	qzh[0]=0;
	scanf("%d %ull",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(mp.find(a[i])!=mp.end())
			mp[a[i]]++;
		else mp[a[i]]=1;
	}
	if(n==1){
		printf("1");
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++){
		b[i]=a[i+1]-a[i];
		qzh[i]=qzh[i-1]+b[i]*i;
	}
	int ans=upper_bound(qzh+1,qzh+n,m)-qzh;
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
#include<bits/stdc++.h>
#define maxn 500005
#define maxm 1000000000000000000ull
typedef long long llong;
typedef unsigned long long ulong;
using namespace std;
int n;
int a[maxn],b[maxn];
ulong m;
llong qzh[maxn];
inline bool chk(int x){
	return qzh[x]<=m;
}
map<int,int>mp;
int erfen(){
	//cout<<"Live\n";
	int l=0,r=n;
	while(l<=r){
		//cout<<"Live\n";
		int mid=l+((r-l)>>1);
		//cout<<"Live\n";
		if(chk(mid)){
			//printf("%d Can!\n",mid);
			l=mid+1;
		}else{
			//printf("%d Cannot!\n",mid);
			r=mid-1;
		}
	}
	return l;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	qzh[0]=0;
	scanf("%d %ull",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(mp.find(a[i])!=mp.end())
			mp[a[i]]++;
		else mp[a[i]]=1;
	}
	if(n==1){
		printf("1");
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++){
		b[i]=a[i+1]-a[i];
		qzh[i]=qzh[i-1]+b[i]*i;
		printf("b[%d]=%d;qzh[%d]=%d\n",i,b[i],i,qzh[i]);
	}
	int ans=upper_bound(qzh+1,qzh+n,m)-qzh;
	if(a[ans]!=a[n]){
		int sheng=qzh[ans-1]+m,jie=b[ans];
		int ans2=qzh[ans-1]+sheng/jie;
		cout<<ans2<<"\n";
		ans2+=mp[a[ans+1]];
		cout<<sheng<<" "<<jie<<" "<<qzh[ans-1]<<" "<<qzh[ans]<<" "<<qzh[ans+1]<<" "<<a[ans+1]<<endl; 
		printf("ans2: %d\n",ans2);
		printf("%d",max(ans,ans2));
	}else{
		printf("%d",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
*/
