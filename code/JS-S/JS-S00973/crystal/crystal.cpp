#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,cnt,a[100005],ans,b[100005],maxn=INT_MIN;
bool check1(){
	for(int i=1;i<=n;i++){
		if(a[i]!=i)
		return false;
	}
	return true;
}
void print1(){
	int x=1;
	n--;
	for(int i=1;i<=n;i++){
		m-=i;
		if(m>=0){
			x++;
			n--;
		}
		else
		break;
		m-=i;
		if(m>=0){
			x++;
			n--;
		}
		else
		break;
	}
	cout<<x<<endl;
}
bool check2(){
	int y=a[2]-a[1];
	for(int i=2;i<=n;i++){
		if(a[i]-a[i-1]!=y)
		return false;
	}
	return true;
	return 0;
}
void print2(){
	int y=a[2]-a[1];
	m/=y;
	if(m+1>n)
	cout<<n;
	else
	cout<<m+1;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
cin>>n>>m;
for(int i=1;i<=n;i++){
	cin>>a[i];
}
if(check1()==1){
	print1();
	return 0;
}
if(check2()==1)
{
	print2();
	return 0;
}
sort(a+1,a+n+1);
int x=1;
while(x<=n){
	ans=0;
	int w=m;
	for(int i=1;i<=n;i++){
		b[i]=a[i];
	}
cnt=a[x];
for(int i=1;i<=n;i++){
	b[i]=abs(cnt-b[i]);
}
sort(b+1,b+n+1);
for(int i=1;i<=n;i++){
	if(b[i]<=w){
		w-=b[i];
		ans++;
	}
 }
 maxn=max(maxn,ans);
 x++;
}
cout<<maxn;
return 0;
}
