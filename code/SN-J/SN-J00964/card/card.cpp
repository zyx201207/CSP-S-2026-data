#include<bits/stdc++.h>
using namespace std;
int main(){
//freopen("card.in","r"stdin);
//freopen("card.out","w",stdout);	
	int n,m; 
    cin>>n>>m;
    int a[n];
    for(int i=1;i<=n;i++);
    		cin>>a[i];
	for(int j=1;j<=n;j++){
    if(a[j]!=a[j+1]){
    	a[j]=a[]
	}
	
		int a1;
		a[j]=a1;
		a[j+1]=a[j];
		a1=a[j+1];
		a[j]=0;
		break;
	}else{
		a[j]=a[j+1];
	}
    }
    a[i]=a[i+1];
    cout<<a[i];
	return 0;
}
