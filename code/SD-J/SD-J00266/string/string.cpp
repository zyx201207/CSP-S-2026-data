#include<bits/stdc++.h>
using namespace std;
int a[200001];
char c[200001];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	long long cnt=0;
	for(int i=1,j=n;i<j;){
		if(c[i]==c[j]){
			if(a[i]==a[j]){
				i++;
				j--;
			}
			else if(a[i]>a[j]){
				a[i]-=a[j];
				j--;
			}
			else{
				a[j]-=a[i];
				i++;
			}
		}
		else{
			if(a[i]==a[j]){
				cnt+=a[i];
				i++;
				j--;
			}
			else if(a[i]>a[j]){
				cnt+=a[j];
				a[i]-=a[j];
				j--;
			}
			else{
				cnt+=a[i];
				a[j]-=a[i];
				i++;
			}
		}
	}
	cout<<cnt;
	return 0;
}
