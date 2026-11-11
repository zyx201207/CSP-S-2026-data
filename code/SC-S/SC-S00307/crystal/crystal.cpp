#include<bits/stdc++.h>
using namespace std;
int n,m;
const int N=2e6;
int a[N];
int b[N];

bool cmp(int x,int y){
	return x<y;
}



int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	int ans=0;
    int k=1;
	int flag=0;
    for(int i=1;i<=n;i++){
        if(ans<m){
			ans+=k;
			k++;
			flag++;
		}
		else if(ans==m){
			
			cout<<flag;
			return 0;
		}
		else if(ans>m){
			cout<<flag-1;
			return 0;
		}
	    
	}
	
	return 0;
}

