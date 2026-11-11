#include<bits/stdc++.h>
using namespace std;
char a[200001];
int b[200001];
int n;
long long num;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	
	for(int i=1;i<=n;i++) cin>>b[i]>>a[i];
	int r=n,l=1;
	while(1){
		if(a[l]==a[r]){
			if(b[l]>b[r]){
				r--;
				b[l]-=b[r+1];
				b[r+1]=0;
			}
			else if(b[l]<b[r]){
				l++;
				b[r]-=b[l-1];
				b[l-1]=0;
			}
			else if(b[l]==b[r]){
				r--;
				l++;
				b[r+1]=0;
				b[l-1]=0;
			}
		}
		else{
			if(b[l]>b[r]){
				r--;
				b[l]-=b[r+1];
				num+=b[r+1];
				b[r+1]=0;
			}
			else if(b[l]<b[r]){
				l++;
				b[r]-=b[l-1];
				num+=b[l-1];
				b[l-1]=0;
			}
			else if(b[l]==b[r]){
				r--;
				l++;
				num+=b[r+1];
				b[r+1]=0;
				b[l-1]=0;
			}
		}
		if(b[l]==0||b[r]==0){
			cout<<num<<endl;
			return 0;
		}
	}
	return 0;
} 
