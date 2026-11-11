#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int a,d;
	cin>>a,d;
	int m;
	vector<int> s;
	for(int i=1;i<=a;i++){
		int y;
		cin>>y;
		s.push_back(y);
}
    int g=s[1];
    for(int i=1;i<=s.size();i++){
    	for(int j=2;i<=s.size();i++){
    		
    		m=i and j;
    		if(m and g==m){
    			g=m;
			}
		}
	}
	cout<<g;
	return 0;
}
