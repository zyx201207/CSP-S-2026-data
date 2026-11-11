#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[n];
    for(int i=0;i<n;i++){
		cin>>a[i];
    }
	for(int j=0;j<n;j++){
		if(m<=0) break;
		if(a[j]<a[j+1]){
			m--;
			a[j]++;
			j=-1;
		}
	}
	int b=0;
	for(int i=0;i<n;i++){
		if(a[i]==a[0]){
			b++;
		}
	}
	cout<<b;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
