#include<bits/stdc++.h> 
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,a=0,x[100000];
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>x[i];
	    a=max(x[i],a);
	}
    if(m==1) {
    	cout<<a;
    	return 0;
    }
    a=0;
    //int z,y;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i!=j){
			   a=max(a,x[i]&x[j]);
		    }
			//z=x[i];
			//y=x[j];
		}
	}
	//cout<<z<" "<<y;
	int l=0x3f3f3f;
	if(n==m){
		for(int i=1;i<=n;i++){
			l&=x[i];
		}
		cout<<l;
		return 0;
	}
	cout<<a;
	return 0;
}
