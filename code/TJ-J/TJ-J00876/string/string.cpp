#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string s;
    int n,su=0,ji=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        int g;
        cin>>g;
        su+=g;
        char c;
        cin>>c;
        for(int i=1;i<=g;i++){
            s+=c;
        }
    }
    int sumax=su/2;
    for(int i=0,j=su-1;sumax!=0;i++,j--){
        if(s[i]!=s[j]){
		    ji++;
		}
		sumax--;
    }
    cout<<ji;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

