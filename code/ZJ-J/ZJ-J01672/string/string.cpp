#include<bits/stdc++.h>
//#define ll long lnog
using namespace std;
int n,a[200010];
long long z,z1[500010],ans;
string s;
char c[200010];
void solve1(){
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++){
			s=s+c[i];
		}
		z+=a[i];
	}
	for(long long i=0;i<z/2;i++){
		if(s[i]!=s[z-i-1]){
			ans++;
		}
	}
	cout<<ans;
}
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	if(n<=10){
		solve1();
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		z1[i]+=a[i]+z1[i-1];
	}
	int l=n,r=n;
	for(int i=1;i<=n;i++){
		if(z>=z1[n]/2)break;
		if(z1[i]>z1[n]/2){
			z1[i]=z1[n]/2;
		}
		for(int j=r;j>i;j--){
			if(z1[n]-z1[j]+1 <=z1[i-1]+1 && z1[n]-z1[j-1]>=z1[i]){
				r=j;
				break;
			}
			if(z1[n]-z1[j]+1>=z1[i-1]+1&&z1[n]-z1[j]+1<=z1[i]&&z1[n]-z1[j-1]>=z1[i]){
				r=j;
				break;
			}
			r=j;
		}
		for(int j=l;j>i;j--){
			if(z1[n]-z1[j]+1 <=z1[i-1]+1 && z1[n]-z1[j-1]>=z1[i]){
				l--;
				break;
			}
			if(z1[n]-z1[j]+1<=z1[i-1]+1 && z1[n]-z1[j-1]<=z1[i]&&z1[n]-z1[j]<=z1[i-1]){
				l--;
				break;
			}
			l--;
		}
		for(int j=l;j<=r;j++){
			if(c[i]!=c[j]){
				if(z1[n]-z1[j]+1 <= z1[i-1]+1 && z1[n]-z1[j-1]>=z1[i]){
					ans+=a[i];
					break;
				}
				if(z1[n]-z1[j]+1 >= z1[i-1]+1 && z1[n]-z1[j]+1<=z1[i]){
					ans+=z1[i]-z1[n]+z1[j];
					continue;
				}
				if(z1[n]-z1[j]+1<=z1[i-1]+1 && z1[n]-z1[j-1]<=z1[i]){
					ans+=z1[n]-z1[j-1]-max(z1[i-1],z1[n]-z1[j]);
					continue;
				}
			}
		}
		z+=a[i];
	}
	cout<<ans;
	return 0;
}