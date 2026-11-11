 #include <bits/stdc++.h>
using namespace std;
string c="",s="",cc="",ss="";
string k;
bool x,y,z,a;
int main() {
    freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	/*cin>>k;
	cout<<k<<endl;
	cout<<k[3]<<endl;
	c+=k[0];c+=k[1];
	s+=k[3];s+=k[4];s+=k[5];
	cc+=k[7];cc+=k[8];
	ss+=k[9];ss+=k[10];ss+=k[11];*/
	cin>>c>>s>>cc>>ss;
	//cout<<c<<s<<cc<<ss<<endl;
	if(c==cc) x=1;
	//cout<<s[0]<<ss[0]<<s[1]<<ss[1];
	if(x==1){
		if(s[0]==ss[0]
		&&s[1]==ss[1])
		y=1;
	}
	if(x==1&&y==1){
		if(s[2]<'D'
		&&ss[2]<'D')
		z=1;
		else if(s[2]>='D'
		&&ss[2]>='D')
		z=1;
	}
	if(x==1&&y==1&&z==1){
		if(s[2]==ss[2]){
			if(abs(s[1]-ss[1])==1)
			a=1;
		}
		else if(s[1]==ss[1]){
			if(abs(s[2]-ss[2])==1)
			a=1;
			else if(s[2]=='F'&&ss[2]=='D')
			a=1;
			else if(ss[2]=='F'&&s[2]=='D')
			a=1;
		}
	}
	cout<<x<<y<<z<<a;
	return 0;
}

