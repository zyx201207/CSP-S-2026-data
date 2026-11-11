#cudlude<bits\stdc++,h>
using namespace std;
int main(){
	string c,s,cc,ss,q{'A','B','C','D','E'};
	cin>>c>>s>>cc>>ss;
	if(c==cc){
		cout<<1;
		if(s[1]==ss[1]&&s[0]==ss[0]){
			cout<<1;
			if(s[2]==ss[2]){
				cout<<1;
				for(int a=0;a<5;a++){
					if(c[2]==q[a]&&s[2]==q[a+1]){
						cout<<1;
				}
		}
	}
}
}
return(0);
}
