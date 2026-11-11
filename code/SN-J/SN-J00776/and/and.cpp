//姓名:张泽凯,考号:SN-J00776,学校:西安交通大学附属中学 
#include<bits/stdc++.h>
using namespace std;
bool cmp(int q,int w){
	return q>w;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,mx=0;
	int a[10003]={}; 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	if(m==1){
		sort(a+1,a+n+1,cmp);
		cout<<a[1];
		return 0;
	}
	if(m==2){
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				mx=max(mx,a[i]&a[j]);
			}
		}
	}
	else if(m==3){
		for(int i=1;i<n-1;i++){
			for(int j=i+1;j<n;j++){
				for(int k=j+1;k<=n;k++){
					mx=max(mx,a[i]&a[j]&a[k]);
				}
			}
		}
	}
	else if(m==4){
		for(int i=1;i<n-2;i++){
			for(int j=i+1;j<n-1;j++){
				for(int k=j+1;k<n;k++){
					for(int h=k+1;h<=n;h++){
						mx=max(mx,a[i]&a[j]&a[k]&a[h]);
					}
				}
			}
		}
	}
	else if(m==5){
		for(int i=1;i<n-3;i++){
			for(int j=i+1;j<n-2;j++){
				for(int k=j+1;k<n-1;k++){
					for(int h=k+1;h<n;h++){
						for(int l=h+1;l<=n;l++){
							mx=max(mx,a[i]&a[j]&a[k]&a[h]&a[l]);
						}
					}
				}
			}
		}
	}
	cout<<mx;
	return 0;
}
