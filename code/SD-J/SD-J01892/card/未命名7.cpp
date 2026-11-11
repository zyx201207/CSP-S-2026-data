#include<bits/stdc++.h>
using namespace std;
struct A{
	int n;
}a[10000];
bool cmp(A a,A b){
	return a>b;
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
    int s;
    cin>>s;
    for(int i=0;i<s;i++){
    	cin>>a[i].n;
	}
	sort(a,a+s,cmp);
	for(int i=0;i<s;i++){
		
	}
	return 0;
} 
//Trick||Treat!
