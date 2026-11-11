#include <bits\stdc++.h>
using namespace std;
struct lxd{
	long long chang;
	char zi; 
};
lxd n[20005];
int a;
long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>a;
	for(int i=1;i<=a;i++){
		cin>>n[i].chang>>n[i].zi;
	}
	long long l=1,r=a;
	while(l<r){
		if(n[l].zi==n[r].zi){
			if(n[l].chang<n[r].chang){
				n[r].chang-=n[l].chang;l++;
			}
			else if(n[l].chang>n[r].chang){
				n[l].chang-=n[r].chang;r--;
			}
			else{l++;r--;}
		}
		else{
			if(n[l].chang<n[r].chang){
				ans+=n[l].chang;n[r].chang-=n[l].chang;l++;
			}
			else if(n[l].chang>n[r].chang){
				ans+=n[r].chang;n[l].chang-=n[r].chang;r--;
			}
			else{ans+=n[l].chang;l++;r--;}
		}
	}
	cout<<ans;
	return 0;
} 
