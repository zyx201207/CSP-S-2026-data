#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int a[n];
	string b[n];
	for(int i=0;i<n;++i){
		cin>>a[i]>>b[i];
	}
	int i=0,j=n-1;
	long long ans=0;
	int x=a[0];
	int y=a[n-1];
	while(i!=j){
		if(b[i]!=b[j]){
			if(x>y){
				ans+=y;
				x-=y;
				j--;
				y=a[j];
			}
			else if(x<y){
				ans+=x;
				y-=x;
				i++;
				x=a[i];
			}
			else{
				ans+=x;
				if(j-i>1){
					i++;
					j--;
					x=a[i];
					y=a[j];
				}
				else break;
			}
		}
		else{
			
			if(x>y){
				x-=y;
				j--;
				y=a[j];
			}
			else if(x<y){
				y-=x;
				i++;
				x=a[i];
			}
			else{
				if(j-i>1){
					i++;
					j--;
					x=a[i];
					y=a[j];
				}
				else break;
			}
		}
	}
	cout<<ans;
	return 0;
}
