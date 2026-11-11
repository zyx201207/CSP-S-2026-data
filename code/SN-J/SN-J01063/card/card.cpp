#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
    long long a,b;
    cin>>a>>b;
    long long n[5005];
    for(long long i=0;i<b;i++) cin>>n[i];
    for(long long i=1;i<=b;i++) cout<<i<<" ";
	fclose(stdin);fclose(stdout); 
	return 0;
} 
