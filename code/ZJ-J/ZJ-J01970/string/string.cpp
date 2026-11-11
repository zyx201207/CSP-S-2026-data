#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    int a[200010];
    char A[200010];
    for(int i=1;i<=n;i++) cin>>a[i]>>A[i];
    long long f=0,f1=1,f2=1,f3=0; 
    for(int i=1;i<=n;i++) f=f+a[i]; 
    char ans[f+10];  
    while(f1<f/2){
    	for(int i=1;i<=n;i++){
	    	for(int j=1;j<=a[i];j++){
	    		ans[f1]=A[i];
	    		f1+=1;
			}
    	}  
	}
    char ans1[f+10];
    while(f2<f/2){
    	for(int i=n;i>=1;i--){
			for(int j=1;j<=a[i];j++){
				ans1[f2]=A[i];
				f2+=1;
			}
	    }
	}
	for(int i=1;i<=f/2;i++){
		if(ans[i]!=ans1[i]) f3+=1; 
	}
	cout<<f3; 
    return 0;
}
