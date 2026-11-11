#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005];
bool id[5005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>a[i];
	if(n<=5){
		int a1=0,a2=0;
		for(int i=0;i<n;i++){
			bool t1=0,t2=0;
			for(int j=i;j<n;j++){
				if(t1==0&&t2==0){
					if(a[j]==1){
						t1=1;
					}else{
						t2=1;
					}
				}else if(t1==1&&t2==1){
					if(a[j]==1){
						t2=0;
					}else{
						t1=0;
					}
				}else{
					if(t1==1&&t2==0){
						if(a[j]==2)t2=1;
					}else{
						if(a[j]==1)t1=1;
					}
				}	
			}
			if(t1)a1++;
			if(t2)a2++;
		}
		cout<<a1<<" "<<a2;
	}
	return 0;
}
