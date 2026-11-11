 #include<bits/stdc++.h>
using namespace std;
long long m,n,a[200050];
int main(){
freopen("and.in","r",stdin);
freopen("ans.out","w",stdout); 
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long l=a[n];
	for(int i=n-1;i>n-m;i--){
		l=l&a[i];
	}
	cout<<l;
	return 0;
}

