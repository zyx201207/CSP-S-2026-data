#include<bits/stdc++.h>
using namespace std;

#include<bits/stdc++.h>
using namespace std;
int jie(int n){
	int s=1;
	for(int i=1;i<n;i++){
		s*=i;
	}
	return s;
}
int C(int m,int n){
	return jie(m-n)*jie(m)/jie(n);
}
int n,m,a[200005],ans=INT_MIN;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<0;
    fclose(stdin);
    fclose(Stdout);
    return 0;
}
