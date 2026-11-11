#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("and.in","r",stdin);
	//freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<int>vec(n);
	for(int i=0;i<n;i++){
		cin>>vec[i];
	}
	sort(vec.begin(),vec.end());
	int x=vec[n-1]&vec[n-2];
	for(int i=n-2;i>n-1-m;i--){
		x&=vec[i];
	}
	cout<<x;
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}


