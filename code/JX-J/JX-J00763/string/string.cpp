#include<bits/stdc++.h>
using namespace std;
long long n,sum=0,tt=0,s=1;
struct x{
    long long num;
    char eng;
}a[10101001];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
        cin>>a[i].num>>a[i].eng;
	}
	for(int i=0;i<n;i++){
        if(a[i].eng==a[i+1].eng){
            s++;
            sum+=a[i].num;
        }
	}
    if(s==n){
        cout<<0;
        return 0;
	}
	cout<<sum;
	return 0;
}
