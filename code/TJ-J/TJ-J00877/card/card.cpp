#include<bits/stdc++.h>
using namespace std;
int n,m,a[500007],t[300007];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	int c=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>=a[i-1]){
			c++;
		}
	}
	if(c==n){
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				t[a[j]]++;
				if(j>i&&a[j]==a[j-1]){
					t[a[j]]--;
				}
			}
		}
		for(int i=1;i<=m;i++){
			cout<<t[i]<<" ";
		}
		cout<<endl;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			t[a[j]]++;
			for(int k=i;k<j;k++){
				if(a[k]==a[j]){
					for(int p=k;p<j;p++){
						t[a[p]]--;
					}
					break;
				}
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<t[i]<<" ";
	}
	cout<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
