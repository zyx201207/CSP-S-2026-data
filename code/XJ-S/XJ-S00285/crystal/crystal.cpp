#include<bits/stdc++.h>
using namespace std;

long long int m;
int n,ans=0,z=0;
long long int a[5000010];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++){
		while(m--){
			if(a[i]<a[i+1]||a[i]>a[i+1]){
				a[i]+=1;
			}else if(a[i]==a[i+1]){
				ans++;
			}
		}
		break;
	}
	cout<<ans;
	return 0;
} 
