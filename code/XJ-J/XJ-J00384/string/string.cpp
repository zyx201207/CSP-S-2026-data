#include<bits/stdc++.h>
#define LL long long 

using namespace std;

const int N=2e5+5;
int n;
int num[N];
char a[N];

signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>num[i]>>a[i];
	}
	int i=1,j=n;
	LL ans=0;
	while(i<j){
		if(a[i]==a[j]){
			if(num[i]==num[j]){
				i++;j--;
			}else if(num[i]<num[j]){
				num[j]-=num[i];
				i++;
			}else{
				num[i]-=num[j];
				j--;
			}
		}else{
			if(num[i]==num[j]){
				ans+=num[i];
				i++;j--;
			}else if(num[i]<num[j]){
				ans+=num[i];
				num[j]-=num[i];
				i++;
			}else{
				num[i]-=num[j];
				ans+=num[j];
				j--;
			}
		}
	}
	cout<<ans;
	return 0;
}
