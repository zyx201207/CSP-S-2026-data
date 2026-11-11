#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int t1,t2,t3,t4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>a>>b>>c>>d;
	int b1=b[0]+b[1];
	int d1=d[0]+d[1];
	if(a==c)
	{
		t1=1;
		if(b1==d1){
			t2=1;
			if(b[2]<='C'&&d[2]<='C'||b[2]>='D'&&d[2]>='D')
			{
				t3=1;
				if(abs(b[2]-d[2])==1){
					t4=1;
				}
			}
		}
	}
	cout<<t1<<t2<<t3<<t4;
	return 0;
}
