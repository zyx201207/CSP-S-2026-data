#include<bits/stdc++.h> 

using namespace std;

bool cmp(const long long& a,const long long& b){
return a>b;
}

long long n,m,c;
long long a[1000005]; 

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	
	sort(a,a+n,cmp);
	
	for(int i=0;i<m-1;i++){
		if(i==0)
			c=a[i]&a[i+1];
		else
			c=c&a[i+1];
	}
	cout<<c;
return 0;
}

