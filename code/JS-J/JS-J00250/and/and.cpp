#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n+10];
	if(m==0){
		cout<<"0";
		return 0;
	}
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(m==1){
		int mx=0;
		for(int i=0;i<n;i++){
			mx=max(mx,a[i]);
		}
		cout<<mx;
		return 0;
	}
	if(m==n){
		int ans=a[0];
		for(int i=1;i<n;i++){
			ans=ans&a[i];
		}
		cout<<ans;
		return 0;
	}
	for(int i=0;i<n;i++){
		if(a[i]>=4){
			break;
		}
		if(i==n-1){
			int f1=0,f2=0,f3=0;
			for(int i=0;i<n;i++){
				if(a[i]==3){
					f1++;
				}
				if(a[i]==2){
					f2++;
				}
				if(a[i]==1){
					f3++;
				}
			}
			if(m==1){
				cout<<"3";
				return 0;
			}else if(m==2){
				if(f1>=2){
					cout<<"3";
					return 0;
				}else if(f1==1){
					if(f2>=1){
						cout<<"2";
						return 0;
					}else if(f3>=1){
						cout<<"1";
						return 0;
					}else{
						cout<<"0";
						return 0;
					}
				}else{
					if(f2>=2){
						cout<<"2";
						return 0;
					}else{
						cout<<"0";
						return 0;
					}			
				}
			}else{
				if(f1>=3){
					cout<<"3";
					return 0;
				}else if(f1==2){
					if(f2>=1){
						cout<<"2";
						return 0;
					}else if(f3>=1){
						cout<<"1";
						return 0;
					}else{
						cout<<"0";
						return 0;
					}
				}else if(f1==1){
					if(f2>=2){
						cout<<"2";
						return 0;
					}else{
						if(f1+f2>=2){
							cout<<"1";
							return 0;
						}else{
							cout<<"0";
							return 0;
						}
					}
				}
				return 0;
			}
		}
	}
	
	return 0;
}
