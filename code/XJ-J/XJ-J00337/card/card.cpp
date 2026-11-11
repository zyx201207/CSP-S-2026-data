#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],t[300005],st[300005];
int main(){
	//freopen("travel.in","r",stdin);
	//freopen("travel.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		t[i]=0;
	}
	if(n==1 && m==1){
		cout<<1;
	}else{
	    for(int i=1;i<=n;i++){
			int s=1;
			for(int j=i;j<=n;j++){
				for(int k=1;k<=s;k++){
					if(t[k]==a[j]){
						s=k;
						for(int l=k+1;l<2*n;l++){
							t[l]=0;
						}
						break;
					}else if(k==s){
						s++;
						t[s]=a[j];
					}
				}
			}	
			for(int j=1;j<=s;j++){
					st[t[j]]++;
				}
			for(int j=1;j<s;j++){
				t[j]==0;
			}
		}
		for(int i=1;i<=m;i++){
			cout<<st[i]<<' ';
		}
	}
	
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}