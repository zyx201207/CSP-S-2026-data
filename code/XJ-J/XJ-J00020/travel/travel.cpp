#include<iostream> 
#include<string>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	char c1,s1,c2,s2;
	if(s1==s2){
	break;
	}
	else if(01<=c1<=16 || 01<=c2<=16 &&  c1==17|| c2==17){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	return 0;
}



