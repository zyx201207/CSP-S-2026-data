#include<bits/stdc++.h>
using namespace std;
long long ant=-1;
int n[200005],n1[200005],m,a;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>a>>m;
	for(int i=1;i<=a;i++){
		cin>>n[i];
	}
	if(m==1){
		for(int i=1;i<=a;i++){
			if(ant<n[i]){
				ant=n[i];
			}
		}
	}
	if(m==2){
		for(int i=1;i<=a;i++){
			for(int j=i+1;j<=a;j++){
				if(n[i]&n[j]>ant){
					ant=n[i]&n[j];
				}
			}
		}
	}
	if(m==3){
		for(int i=1;i<=a;i++){
			for(int j=i+1;j<=a;j++){
				for(int k=j+1;k<=a;k++){
					if((n[i]&n[j]&n[k])>ant){
						ant=(n[i]&n[j]&n[k]);
					}
				}
			}
		}
	}
	if(m>3){
		for(int i=2;i<=a;i++){
			n[i]=n[i]&n[i-1];
		}
		for(int i=2;i<=a;i++){
			if(n[i]>ant){
				ant=n[i];
			}
		}
	}
	cout<<ant;
	return 0;
}
