//zhang bo yang     yan an shi xing qu di si zhong xue SN-J00672
#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel1.in","t",stdin);
	freopen("travel1.out","w",stdout);
	int c1,c2;
	int s1,s2;
    cin>>c1>>s1>>c2>>s2;
    int a=max(s1,s2);
	int b=min(s1,s2);
	if(c1==c2){
		cout<<1<<" ";
	}else{
		cout<<0<<" ";
	} 
	if('s1'!=s2 && 's1'-('s1'%100)=='s2'-('s2'%100)){
		cout<<1<<" ";
	}else{
		cout<<0<<" ";
	} 
	if(('s1'%100>=37 &&'s1'%100<=39 && 's2'%100>=37 &&'s2'%100<=39) &&('s1'%100>=40 &&'s1'%100<=41 && 's2'%100>=40 &&'s2'%100<=41) && ('s1'!='s2')){
		cout<<1<<" ";
	}else{
		cout<<0<<" ";
	} 
	if('a'-'b'==1 && 'b'%100!='39'){
		cout<<1<<" ";
	}else{
		cout<<0<<" ";
	}
	cout<<c1<<c2;
}





























































