#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    char p11=s1[0],p12=s1[1],p21=s2[0],p22=s2[1];
    char z1=s1[2],z2=s2[2];//zuoweihao
    if(c1!=c2){//different chexiang
        cout<<"0000"<<'\n';
    }
    else{//same chexiang
        if(!(p11==p21&&p12==p22)){//dif pai
            cout<<"1000"<<'\n';
        }
        else{//sa pai
            if((z1<='C'&&z2>='D')||(z1>='D'&&z2<='C'))//dif ce
            {
                cout<<"1100"<<'\n';
            }
            else {//sa ce
                if(abs(int(z1)-int(z2))==1||(z1=='D'&&z2=='F')||(z1=='F'&&z2=='D')){
                    cout<<"1111"<<'\n';
                }
                else{
                    cout<<"1110"<<'\n';
                }
            }
        }
    }
    return 0;
}
