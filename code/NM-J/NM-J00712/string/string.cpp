#include<bits/stdc++.h>
using namespace std;
bool pd(string x){
    int n=x.size();
    for(int i=0;i<n;i++){
        if(x[n-i-1]!=x[i]){
            return 0;
        }
    }
    return 1;
}
int n,s=0;
string a;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    int cnt=0;
    for(int i=0;i<n;i++){
        int x;
        char y;
        cin>>x>>y;
        while(x--){
            a.push_back(y);
        }
    }
    long long l=a.size();
    while(!pd(a)){
        for(long long i=0;i<l;i++){
            if(a[l-i-1]!=a[i]){
            	a[l-i-1]=a[i];
                s++;
                break;
                cout<<a<<"\n";
            }
    	}
    }
    cout<<s;
    fclose(stdin);
    fclose(Stdout);
    return 0;
}
