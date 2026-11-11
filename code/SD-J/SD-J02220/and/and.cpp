#include<iostream>
using namespace std;
int c,s,p,cnt;
int j[200010],k[200010];
int ka(int k1){
	int hh=k[0];
	for(int i=0;i<k1;i++){
    	hh=hh&k[i];
    	//debug:
//    	cout<<"k[i]:"<<k[i]<<" % hh:"<<hh<<" #\n";
    	
	}
	return hh;
}
int ak(int ss,int pp){
	if(pp==s){
		//debug:
//		cout<<1<<' '<<ss<<' '<<c<<endl;
		for(int i=ss;i<c;i++){
			k[pp]=j[i];
			int hhh=ka(s);
    		cnt=max(cnt,hhh);
    		//debug:
//    		for(int i=0;i<pp;i++){
//				cout<<' ';
//			}	
//    		cout<<"i:"<<i<<" @ ka:"<<hhh<<" &\n";
		}
		
	}
	//debug:
//	cout<<pp<<endl;
	for(int i=ss;i<c;i++){
		
    	//debug:
//    	for(int i=0;i<pp;i++){
//			cout<<' ';
//		}
//    	cout<<"i"<<pp<<":"<<i<<" *\n";
    	//:end
    	k[pp]=j[i];
    	ak(i+1,pp+1);
	}
	return 0;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    cin>>c>>s;
    for(int i=0;i<c;i++){
    	cin>>j[i];
	}
	ak(0,0);
	cout<<cnt<<endl;
	return 0;
}

