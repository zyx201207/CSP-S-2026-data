#include<bits/stdc++.h>
using namespace std;
long long a[500000];
vector<int> s;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int c[m];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			for(int k=i;k<j;k++){
				if(a[j]==a[k]){
					s.clear();
				}
			}
			s[i]+=a[j];
		}
		c[s[i]]++;
	}
	for(int i=0;i<m;i++){
		cout<<c[i]<<" ";
	}
	return 0;
}
