#include <bits/stdc++.h>
using namespace std;
string two(int a){
	string c,c1;
	while(a!=0){
		c+=a%2+'0';
		a/=2;
	}
	
	
	for(int i=c.size()-1;i>=0;i--){
		c1+=c[i];
	}return c1;
}
int main(){
	int n,m,a[20005],ma=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			string l,m;
			l=two(a[i]);
			m=two(a[j]);
			for(int i=1;i<=min(l.size(),m.size());i++){
				int cnt=0;
				if(l.size()-i==m.size()-i){
					//cout<<"l:"<<l<<" m:"<<m<<endl;
					cnt++;
					//cout<<"cnt:"<<cnt<<endl;
				}
				else{
					
					if(cnt>ma){
						ma=cnt;
					break;
						
					}
				}
			}
		}
	}cout<<ma;
	return 0;
}   
