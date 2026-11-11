#include<bits/stdc++.h>
using namespace std;
char a[200005];
long long n,alen[200005],ans=0;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>alen[i]>>a[i];
		
	}
	int l=1,r=n;
	while(l<r){
		if(a[l]==a[r]){
//			cout<<111;
			if(alen[l]<alen[r]){
//				cout<<"aaaa";
				alen[r]-=alen[l];
				l++;
				
			}else if(alen[l]>alen[r]){
//				cout<<"bbbb";
				alen[l]-=alen[r];
				r--;
				
			}else{
//				cout<<"cccc";
				l++;
				r--;
			}
		}else{
//			cout<<2222;
			if(alen[l]<alen[r]){
//				cout<<"a1a1";
				ans+=alen[l];
				alen[r]-=alen[l];
				l++;
				
			}else if(alen[l]>alen[r]){
//				cout<<"b2b2";
				ans+=alen[r];
				alen[l]-=alen[r];
				r--;
				
			}else{
				ans+=alen[l];
				l++;
				r--;
			}
		}
		
	}
	cout<<ans;
	return 0;
}