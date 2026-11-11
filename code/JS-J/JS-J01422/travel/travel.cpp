#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
	char a,b,c,d,e,f,g,h,i,j;
	cin>>a>>b>>c>>d>>e>>f>>g>>h>>i>>j;
	int a1,b1,c1,d1;
	a1=int(a)+int(b);
	b1=int(c)+int(d)+int(e);
	c1=int(f)+int(g);
	d1=int(h)+int(i)+int(j);

    if(a1==c1){
            cout<<1;
		if(int(c)+int(d)==int(h)+int(i)){
            cout<<1;
		    if(int(e)==int(j)+1==67||int(e)==int(j)-1==66||int(e)==int(j)+2==67||int(e)==int(j)-2==65||int(e)==int(j)-2==68||int(e)==int(j)+2==70)
            {
                cout<<1;
                if(int(e)==int(j)+1==67||int(e)==int(j)-1==66||int(e)==int(j)-2==68||int(e)==int(j)+2==70)
                   cout<<1;
                else
                    cout<<"0";
            }
            else
                cout<<"00";
		}
		else cout<<"000";
    }
	else
		cout<<"0000";
	return 0;
}
