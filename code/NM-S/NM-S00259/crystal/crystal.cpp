#include<bits/stdc++.h>
using namespace std;
int a[10000001],b[10000001];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m,num=0,cs,sum=0;
    cin >> n >> m;
    for(int i=0;i<n;i++){
    	cin >> a[i];
	}
	num=m;
	sort(a,a+n);
	for(int i=0;i<n;i++){
    	num+=a[i];
    	if(num/a[i+1]==2){
    		cs=a[i+1];
    		sum++;
    		break;
		}
		sum++;
	}
	for(int i=0;i<n;i++){
    	if(a[i]==cs){
    		sum++;
		}
	}
	cout <<sum;
    return 0;
}
