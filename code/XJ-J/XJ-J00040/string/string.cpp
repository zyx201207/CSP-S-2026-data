#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string .in","r",stdin);
	freopen("string .out","w",stdout);
	int n,x,f;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x;
	}
	for(int i=n;i>=1;i--){
	cin>>f;
	}
	int cnt=0;
    if (x!=f){ 
	int l ,r;
	cin>>l>>r;
	int mid=(l+r)/2;
	for(int i=l;i<=mid;i++){
		for(int i=r;i<=mid+1;r--){
			if(l!=r){
				l=r;
			}
			else 
			{
				l++;
				r--;
				cnt++;
			}
		}
	}
	cout<<cnt;
   } 
   else {
   	cout<<"0";
   }
	
	return 0;

} 

