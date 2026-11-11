

#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2,s3,s4;
char a,b;
int cnt1,cnt2,f,f2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1;
	for(int i=1;i<=3;i++){
        cin>>a;
		if(cnt1<2){
		s1+=a;
		cnt1++;
	}else if(cnt1==2){
		cnt1++;
		s3+=a;
		}
	}
	cin>>c2;
	for(int i=1;i<=3;i++){
        cin>>b;
		if(cnt2<2){
		s2+=b;
		cnt2++;
	}else if(cnt2==2){
		cnt2++;
		s4+=a;
		}
	}
	if(c1==c2){
		cout<<1;
	}else{
		cout<<0;
	}
	if(s1==s2 and c1==c2){
            f2=1;
		cout<<1;
	}else{
		cout<<0;
	}
	if(f2==1){
        if(s3=="A" or s3=="B" or s3=="C"){
		if(s4=="A" or s4=="B" or s4=="C"){
			cout<<1;
			f=1;
		}
	}else if(s3=="D" or s3=="F"){
		if(s4=="D" or s4=="F'"){
			cout<<1;
			f=1;
		}
	}else cout<<0;
	}else cout<<0;


	if(f==1){
		if(s3=="A" and s4=="C"){
			cout<<0;
		}else if(s4=="A" and s3=="C"){
			cout<<0;
		}else{
			cout<<1;
		}
	}else{
		cout<<0;
	}
	return 0;
}


