#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char c1[3],c2[3],s1[3],s2[3];
	cin>>c1>>s1>>c2>>s2;
	int a=0,b=0,n=10,c=0,d=0;
	for(int i=0;i<2;i++){
		c+=(c1[i]-'0')*n;
		d+=(c2[i]-'0')*n;
		a+=(s1[i]-'0')*n;
		b+=(s2[i]-'0')*n;
		n/=10;
	}
	if(c==d&&c!=16&&d!=16&&c>1&&c<=17&&d>1&&d<=17){
		cout<<1;
	}else{
		cout<<0<<0<<0<<0;
		return 0;
	}
	if(a==b){
		cout<<1;
		if(s1[2]<='C'&&s2[2]>='D'||s2[2]<='C'&&s1[2]>='D'){
		    cout<<0<<0;
	    }else{
		    cout<<1;
		    if(s1[2]+1==s2[2]||s1[2]-1==s2[2]){
			    cout<<1;
		    }else{
			    cout<<0;
		    }
	    }
	}else{
		cout<<0<<0<<0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
