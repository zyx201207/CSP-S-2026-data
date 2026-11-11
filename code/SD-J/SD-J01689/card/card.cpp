#include<bits/stdc++.h>
using namespace std;
int main(){
//	freopen("card.in","r",stdin);
//	freopen("card.out","w",stdout);
	int n,m,time=0;
	string s;
	string a;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>s[i];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			for(int k=1;k<n;k++){
				if (s[j]==s[k]){
					for(int h=0;h<n;h++)
					a[h]=s[k];
				}
			}
		}
	}
	for(int i=0;i<n;i++) 
		for(int j=0;j<n;j++){
			if(a[j]=j){
				time++;
				break;
			}
		cout<<time<<" ";	
		}

return 0;
}
