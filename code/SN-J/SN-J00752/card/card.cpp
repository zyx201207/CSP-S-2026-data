#include<bits/stdc++.h>
#include<vector>
using namespace std;
int main(){
	int m,n;
	cin>>n>>m;
	int a[n];
	int res[m];
	for(int i=0;i<m;i++){
		res[i]=0;
	}
	vector<int> s;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		bool b[m];int c[m];
		for(int j=0;j<m;j++){
			b[m]=0;c[m]=0;
		}
		s.clear();
		for(int j=i;j<n;j++){
			s.push_back(a[j]);
		}
		for(int j=0;j<n-i;j++){
			if(b[s[j]]==0){
				b[s[j]]=1;
				c[s[j]]=j;
			}else{
				for(int k=c[s[j]];k<j;k++){
					b[s[k]]=0;
					s[k]=0;
				}
				b[s[j]]=1;
				c[s[j]]=j;
			}
		}
		for(int j=0;j<m;j++){
			cout<<b[j]<<" ";
			res[j]+=b[j];
		}
	}
	for(int i=0;i<m;i++){
		cout<<res[i]<<" ";
	}
}
