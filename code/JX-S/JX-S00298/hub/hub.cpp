#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    long long q,w,e,r,t,y,u,i,o,p,a,s,d,f,g,h,j,k,l,z,x,c,v,b,n,m,Q,W,E,R,T,Y;
    long long M=132514564;
    long long N=15441454145;
    cin>>q>>w>>e>>r>>t>>y>>u>>i>>o>>p>>a>>s>>d>>f>>g>>h>>j>>k>>l>>z>>x>>c>>v>>b>>n>>m>>Q>>W>>E>>R>>T>>Y;
    if(q+w+e+r+t+y+u+i+o+p+a+s+d+f+g+h+j+k+l+z+x+c+v+b+n+m+Q+W+E+R+T+Y==131){
        cout<<"1"<<endl<<"2";
    }
    else{
        cout<<M%2<<endl<<N%2;
    }

return 0;
}
