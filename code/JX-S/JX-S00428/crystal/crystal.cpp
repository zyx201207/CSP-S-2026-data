#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    vector<int> o;
    int a,b,c,d,e=1;
    cin>>a>>b;
    d=b;
    for(int i=0; i<a; i++){
        cin>>c;
        o.push_back(c);
    }
    sort(o.begin(),o.end());
    for(int j=0; j<a; j++){
        if(o[j]<o[j+1]){
           d=d-(j+1)*(o[j+1]-o[j]);
           e=e+1;
	    }else if(o[j]==o[j+1]){
		   e=e+1;
		}
           if(d<0){
              break;
           }
    }
    cout<<endl;
    cout<<e-1;
    return 0;
}
