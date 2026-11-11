#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen ("travel.in","r",stdin);
    freopen ("travel.out","w",stdout);
	char a,b,c,d;
	cin>>a>>b>>c>>d;
	int e=int('0')+int('0')+int('A')+96;
	if(a==c){
        cout<<1;

        if(b>d&&b-d<=5||d>b&&d-b<=5){
            cout<<1;
            if((b-e)%10<=2&&(d-e)%10>=3||(d-e)%10<=2&&(b-e)%10>=3){
                cout<<0<<0;
            }
            else{
                cout<<1;
                if((b-e)%10-(d-e)%10==1||(d-e)%10-(b-e)%10==1){
                    cout<<1;

                }
                else{
                    cout<<0;
                }
            }


        }
        else {
            cout <<0<<0<<0<<0;

        }

	}
	else{
        cout<<0<<0<<0<<0;

	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
