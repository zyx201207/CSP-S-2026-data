#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n=0;
	cin>>n;
	int jieguo=0;
	
	vector<string>v(2*n);
	for(int i=0;i<=n;i++){
		int a=0;
		cin>>a;
		v.push_back(a,a);
		
	}
	for(int j=0;j<=2*n;j++){
		if (v[0]!=v[2*n-1]){
		jieguo+=1;
	    }
	    v[0]+=1;
	    v[2*n-1]-=1;
    }
	
	cout<<jieguo;
	return 0;
}
