#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 200005

int n,cnt;
int a[N];
char s[N];

signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i]>>s[i];
	}
	int i=1,j=n;
	while(i<j){
		if(s[i]==s[j]){
			if(a[i]>a[j]){
				a[i]-=a[j];
				j--;
				continue;
			}
			else if(a[i]<a[j]){
				a[j]-=a[i];
				i++;
				continue;
			}
			else{
				i++;
				j--;
				continue;
			}
		}
		else{
			if(a[i]>a[j]){
				cnt+=a[j];
				a[i]-=a[j];
				j--;
				continue;
			}
			else if(a[i]<a[j]){
				cnt+=a[i];
				a[j]-=a[i];
				i++;
				continue;
			}
			else{
				cnt+=a[i];
				i++;
				j--;
				continue;
			}
		}
	}
	cout<<cnt<<'\n';
	return 0;
} 
