#include<bits/stdc++.h>
using namespace std;
int a[300005],a1[300005],a2[300005],n,m,j;
int main(){
	freopen("card.in",stdin);
    freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	string a;
	cin>>n>>m;
	for(int i=1;i++;i<=n){
		cin>>a[j];
	}
	for(int i=1;i++;i<=n){
		for(int s=i;s++;s<=n){
			a1[s]=1;
			for(int p=1;p++;p<=s){
				if(a[p]==a[s]){
					for(int q=p;q<=s;q++){
						a1[q]=0;
					}
				}
			}
		}
		for(int d=1;d++;d<=n){
			if(a1[d]==1&&a2[a[d]]<i){
				a2[a[d]]+=1;
			}
		}
	}
	for(int i=1;i++;i<=m){
		cout<<a2[i]<<' ';
	}
	fclose(stdin);
	fclose(stdout);	
	return 0;
}
