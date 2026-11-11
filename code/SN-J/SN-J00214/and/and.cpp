#include <bits/stdc++.h> 
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int a,b;
	cin>>a>>b;
	int q[200009],w[200009];
	for(int i=1;i<=a;i++){
		cin>>q[i];
	}	
	for(int i=1;i<=a;i++){
		for (int j=1;j<=a;j++){
			w[i]==q[i]&&q[i+1];
		}
			
	}
	sort(w+1,w+1+a,cmp);
	cout<<w[1];
	return 0;
}
	
