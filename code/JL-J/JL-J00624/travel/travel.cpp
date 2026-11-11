   #include <bits/stdc++.h>
    using namespace std;
    string c1,s1,c2,s2;
    bool f=true,f1=true,f2=true;
    char cs1,cs2;
    int main(){
        freopen("travel.in","r",stdin);
        freopen("travel.out","w",stdout);
            cin>>c1>>s1>>c2>>s2;
            if(s1.find('A')&&s2.find('F')){
                f1=false;
            }
              if(s1.find('F')&&s2.find('A')){
                f1=false;
            }
            if(s1.find('B')&&s2.find('F')){
                f1=false;
            }
                if(s1.find('F')&&s2.find('B')){
                f1=false;
            }
                if(s1.find('F')&&s2.find('C')){
                f1=false;
            }
                if(s1.find('C')&&s2.find('F')){
                f1=false;
            }
                if(s1.find('A')&&s2.find('D')){
                f1=false;
            }
                if(s1.find('D')&&s2.find('A')){
                f1=false;
            }
                if(s1.find('B')&&s2.find('D')){
                f1=false;
            }
                if(s1.find('D')&&s2.find('B')){
                f1=false;
            }
                if(s1.find('C')&&s2.find('D')){
                f1=false;
            }
                if(s1.find('D')&&s2.find('C')){
                f1=false;
            }

            if(s1.find('A')&&s2.find('C')){
                f=false;
            }
              if(s1.find('C')&&s2.find('A')){
                f=false;
            }

        if(s1.find('D')&&s2.find('F')&&f2==true){
            cout<<"1011";
        }else{
        cout<<"1"<<"1"<<f1<<f;
        }


        return 0;
    }
