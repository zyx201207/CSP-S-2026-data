#include<bits/stdc++.h>
using namespace std;
int sy,sr;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>sy>>sr;
	int s[200005];
	for(int i=0;i<sr;i++){
		cin>>s[i];
	}
	int m=0;
	for(int i=0;i<sr;i++){
		for(int j=i;j<sr;j++){
			if(s[i]&s[j]>m){
				m=s[i]&s[j];
			}
		}
	}
	cout<<m;
	return 0;
}
