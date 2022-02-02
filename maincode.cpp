#include<bits/stdc++.h>
#include<conio.h>

#define ofsm ofstream 
#define ifsm ifstream
using namespace std;

int rec[2][20000],lang;
double simi[105][105];
string range,ranger;

double LCS(int a,int b);

bool Search(int x,int m);
bool Stop();

void chooserange();
void LCS_pre();
void ran();
void language();
void UsingManual(int t);
void Upload();
void Download();
void NewVocs();
void Review();
void VocsList();
void Record(int x,int m);
void arrange();
void show();
void Email();
void Exam();
void version();
void Clear();

int main(){
	Download();
	UsingManual(0);
	language();
	ran();
	
	while(1){
		system("cls");
		UsingManual(1);
		int m;
		cin >>m;
		system("cls");
		if(m==1)NewVocs();
		else if(m==2)VocsList();
		else if(m==3)Review();
		else if(m==4)UsingManual(2);
		else if(m==999)Email();
		else if(m==777)Exam();
		else if(m==5)ran(); 
		else if(m==6)break;
		else if(m==7)LCS_pre();
		else if(m==8)version();
		else if(m==9)Clear();
	}
    
	Upload();
	return 0;
}

void chooserange(){
	int n,x;
	string s[50];
	ifsm f("ItemsList.txt");
	range.clear();ranger.clear();
	
	if(lang==0)cout<<"Please Enter the range code\n";
	if(lang==1)cout<<"請按下對應的範圍按鍵\n";
	
	f>>n;
	for(int i=1;i<=n;++i){
		f>>s[i];
		cout<<"("<<(char)(i+64)<<")"<<s[i]<<'\n';
	}
	while(1){
		if(_kbhit()){
			int ch=_getch();cout<<ch<<'\n';
			int x=ch-64;if(ch>96)x+=64-96;
			if(x>n || x<0){
				if(lang==0)
					cout<<"Please Enter the correct number\n";
				if(lang==1)
					cout<<"請按下正確的代碼\n";
				
			}else{
				ranger=s[x]+"_rec.txt";
    			range =s[x]+".txt";
				system("cls");
				return;
			}
			
		}
	}
	
}

void ShowVoc(int x,int m){
	string en,ch;
	const int loc=0;
	ifsm f;
	f.open(range);
    f.seekg(loc);f>>ch>>ch>>ch;
    ch.clear();
    
    for(int j=0;j<x;j++)f>>en>>ch;
    
    //m=0:English	m=1:Chinese
    if(m==0)cout<<en<<'\n';en.clear();
	if(m==1)cout<<ch<<'\n';ch.clear();
	
}

void LCS_pre(){
	for(int i=1;i<=100;i++){
		for(int j=1;j<=100;j++){
			simi[i][j]=LCS(i,j);
		}
	}
	for(int i=1;i<=100;i++){
		for(int j=1;j<=100;j++){
			if(simi[i][j]>0.7){
				cout<<i<<" "<<j<<'\n';
				ShowVoc(i,0);
				ShowVoc(j,0);
			}
		}
	}
	Stop();
}

double LCS(int a,int b){
	double lcs[30][30]={0};
	int tmp;
	const int loc=0;
	string S1,S2,s1,s2,ch;
	
	ifsm f;
	f.open(range,ios::in);
	if(!f)cout<<"REEOR\n";
	
	f.seekg(loc);
	f>>tmp>>tmp>>tmp;
	for(int j=0;j<a;j++)f>>S1>>ch;
	
	f.seekg(loc);
	f>>tmp>>tmp>>tmp;
	for(int j=0;j<b;j++)f>>S2>>ch; 
	
    int n1=S1.size();
    int n2=S2.size();
    double len=min(n1,n2);
    
    for(int i=0;i<n1;i++)s1[i+1]=S1[i];
    for(int i=0;i<n2;i++)s2[i+1]=S2[i];
	for(int i=0;i<=n1;i++)lcs[i][0]=0;
	for(int j=0;j<=n2;j++)lcs[0][j]=0;
	
	for(int i=1;i<=n1;i++)
	    for(int j=1;j<=n2;j++)
	        if(s1[i]==s2[j]){
	            lcs[i][j]=lcs[i-1][j-1]+1;
	        }
	        else{
	            if(lcs[i-1][j]<lcs[i][j-1]){
	                lcs[i][j]=lcs[i][j-1];
	            }
	            else{
	                lcs[i][j]=lcs[i-1][j];
	            }
	        }
	//cout<<a<<" "<<b<<" "<<lcs[n1][n2]<<'\n';
	return lcs[n1][n2]/len;
}

void language(){
	while(1){
		if(_kbhit()){
			int ch=_getch();
			cout<<ch<<'\n';
			if(ch==101 || ch==69){
				lang=0;
				return;
			}else if(ch==99 || ch==67){
				lang=1;
				return;
			}
			else {
				cout<<"Please Press E or C\n";
				cout<<"請按下E或是C\n";
			}
		}
	}	
}

void ran(){
	//range 
	system("cls");
	if(lang==0)cout<<"Please enter the range of the words\n";
    else if(lang==1)cout<<"請輸入單字範圍\n";
    cin >>range;
    if(range=="choose")chooserange();
	else {
		ranger=range+"_rec.txt";
    	range+=".txt";system("cls");		
	}
	return;
}

void Exam(){
	srand(time(0));
	string e,c;
	const int loc=0;
	int n=50,arr[200],x;
	
	for(int i=0;i<200;i++)arr[i]=i+1;
	random_shuffle(arr,arr+100);
	
	ifsm fin;ofsm fout;
	fin.open(range,ios::in);
	fout.open("test.txt",ios::out);
	if(!fin)cout<<"ERROR\n";
	
	if(lang==0)cout<<"Please enter the number of the words\n";
	if(lang==1)cout<<"請輸入單字數量\n";
	
	cin >>n;
	for(int i=1;i<=n;i++){
	    fin.seekg(loc);fin>>x>>x>>x;
		x=arr[i];
		cout<<x<<'\n';e.clear();
	    for(int j=0;j<x;j++)fin>>e>>c;
	    cout<<e<<'\n';
		fout<<i<<"."<<e;
		if(i%2==0)fout<<"\n\n";
		else for(int j=e.size();j<30;j++)fout<<" ";
	}
}

void UsingManual(int t){
	system("cls");
	if(lang==0){
		if(t==0){
			cout<<"Welcome to W_X_Dai's vocabularies examine\n";
			cout<<"It can help you to memory the vocabularies\n";
			cout<<"Press E to continue with English mode...\n";
			cout<<"按下C以中文模式繼續...\n"; 
			Stop();
			return;
		}
		if(t==1){
			cout<<"Enter the Mode Code to continue\n";
			cout<<"Mode Code 1:New vocabularies\n";
			cout<<"Mode Code 2:Vocabularies List\n";
			cout<<"Mode Code 3:Review\n";
			cout<<"Mode Code 4:Using introduction\n";
			cout<<"Mode Code 5:Change vocabularies range\n";
			cout<<"Mode Code 6:Exit\n";
			cout<<"Mode Code 999:Connect us or Donate:)\n";
			cout<<"Please enter the Mode Code...\n"; 
			cout<<">>>";
		}
		if(t==2){
			cout<<"Introductions\n";
			cout<<"When having an exam,pressing any button to continue\n";
			cout<<"Press Enter or the raw of qwer means you have completely memorized the word\n";
			cout<<"Press other buttons means you need to memorize that word again\n";
			cout<<"You can review those words in the Review Mode By the Mode Code 3\n";
			cout<<"Other questions you can use Mode Code 999 to ask W_X_Dai\n";
			cout<<"Press any button to continue...\n";
			Stop();
			return;
		}		
	}else if(lang==1){
		if(t==0){
			cout<<"歡迎來到 W_X_Dai 的英文測驗系統\n";
			cout<<"這可以幫助你背誦單字\n";
			cout<<"請按任意鍵繼續...\n";
			Stop();
			return;
		}
		if(t==1){
			cout<<"輸入代碼以選擇模式\n";
			cout<<"代碼1:練習新單字\n";
			cout<<"代碼2:顯示單字表\n";
			cout<<"代碼3:複習錯誤單字\n";
			cout<<"代碼4:使用說明書\n";
			cout<<"代碼5:改變單字範圍\n";
			cout<<"代碼6:退出本系統\n";
			cout<<"代碼999:聯絡我們或是抖內:)\n";
			cout<<"輸入代碼以繼續...\n"; 
			cout<<">>>";
		}
		if(t==2){
			cout<<"使用說明\n";
			cout<<"測驗時，按下任意鍵繼續\n";
			cout<<"按下Enter或者是qwer那一排的字母代表你已經背熟該單字\n";
			cout<<"其他按鍵代表你需要複習該單字\n";
			cout<<"你可以使用代碼3進入複習模式\n";
			cout<<"有其他問題可以使用代碼999聯絡我們\n";
			cout<<"按下任意鍵以繼續...\n";
			Stop();
			return;
		}				
		
	}
}

void show(){
	if(lang==0)cout<<"Review List:";
	else if(lang==1)cout<<"複習列表:";
	for(int i=0;i<=rec[0][0];i++)
		cout<<rec[0][i]<<" ";
	/*cout<<"\n1:";
	for(int i=0;i<=rec[1][0];i++)
		cout<<rec[1][i]<<" ";*/
	cout<<'\n';
}

bool Search(int x,int m){
	int l=rec[m][0];
	for(int i=1;i<=l;i++){
		if(rec[m][i]==x)return 1;
	}
	
	if(m==0)m=1;
	else m=0;
	
	l=rec[m][0];
	for(int i=1;i<=l;i++){
		if(rec[m][i]==x){
			rec[m][i]=0;
		//	rec[m][0]--;
		}
	}
	
	if(m==0)m=1;
	else m=0;
		
	return 0;
}

void arrange(){
	for(int j=0;j<2;j++){
		int tmp[20000]={0},t;
		for(int i=1;i<=rec[j][0];i++){
			if(rec[j][i]!=0){
				tmp[0]++;
				tmp[tmp[0]]=rec[j][i];
			}
		}
		rec[j][0]=tmp[0];
		t=tmp[0];
		sort(tmp+1,tmp+1+t);
		for(int i=0;i<=t;i++){
			rec[j][i]=tmp[i];
		}
	}
//	show();
}

void Record(int x,int m){
	if(Search(x,m)==1)return;
	rec[m][0]++;
	rec[m][rec[m][0]]=x;
//	show();
	arrange();
}

bool Stop(){
	int list[11]={113,119,101,114,116,121,117,105,111,112,13};
	while(1){
		if(_kbhit()){
			int ch=_getch();
			for(int i=0;i<10;++i){
				if(ch==list[i])return 1;
			}
			return 0;
		}
	}
}

void Download(){
	ifsm f;
	f.open(ranger,std::ios::in);
	f>>rec[0][0];
	for(int i=1;i<=rec[0][0];i++)f>>rec[0][i];
	
	f>>rec[1][0];
	for(int i=1;i<=rec[1][0];i++)f>>rec[1][i];	
}

void Upload(){
	
	ofsm f;
	f.open(ranger,std::ios::trunc);
	
	f<<rec[0][0];
	for(int i=1;i<=rec[0][0];i++)f<<" "<<rec[0][i];
	
	f<<"\n"<<rec[1][0];
	for(int i=1;i<=rec[1][0];i++)f<<" "<<rec[1][i];	
}

void Review(){
	int que[20000]={0};
	for(int i=1;i<=rec[0][0];i++){
		que[i-1]=rec[0][i];
	}
	random_shuffle(que,que+rec[0][0]);
	
	ifsm f;
	string en,ch;
    int b,e,n,x,t;
    const int loc=0;
    
    f.open(range,std::ios::in);
    f>>b;f>>e;f>>t;
    
    if(lang==0){
	    cout<<"Review Mode\n";
	    cout<<"How many vocabularies do you want to review?\n";	
	}else if(lang==1){
		cout<<"複習模式\n";
		cout<<"你想要複習幾個單字?\n";
	}
    cin >>n;
    
    int it=1;
    for(int i=0;i<n;i++){
    	system("cls");
    	if(que[i]==0){
    		if(rec[0][0]!=0){
    			for(int i=1;i<=rec[0][0];i++){
					que[i-1]=rec[0][i];
				}
				random_shuffle(que,que+rec[0][0]);
				i=0;
			}else{
	    		if(lang==0){
	    			cout<<"You have reviewed all you want to review\n";
	    			cout<<"Pressing any button to continue...";
				}else if(lang==1){
					cout<<"你已經複習完所有單字了!\n";
					cout<<"按下任意鍵以繼續...";
				}
				Stop();
				return; 				
			}	
			
		}
    	cout<<it<<"/"<<n<<'\n'; 
    	f.seekg(loc);f>>b>>e>>t;
        x=que[i];
        cout<<x<<".";
        
        //show english
        for(int j=0;j<x;j++)f>>en>>ch;
        cout<<en<<'\n';en.clear();
		//show chineser();
		Stop();
		
		cout<<ch<<'\n';ch.clear();
		Record(x,Stop());
		it++;if(it>n)return;
    }

}

void NewVocs(){
    srand(time(0));
    
    ifsm f;
    string en,ch;
    int b,e,n,x,t,tmp[5000];
    const int loc=0;
    for(int i=0;i<5000;++i)tmp[i]=i+1;
    
    f.open(range,std::ios::in);
    f>>b;f>>e;f>>t;
    
    
    if(lang==0){
	    cout<<"These vocabularies are from "<<b<<" to "<<e<<'\n';
	    cout<<"How many vocabularies do you want to practice?\n";	
	}else if(lang==1){
		cout<<"單字範圍:"<<b<<"~"<<e<<'\n';
		cout<<"你想要練習幾個單字?\n"; 
	}
	int ttmp=1;cin >>n;
	
	for(int i=0;i<5000;++i){
		tmp[i]=ttmp;
		ttmp++;
		if(ttmp>t)ttmp-=t;
	}
	if(n>t){
		random_shuffle(tmp,tmp+t);
	 	random_shuffle(tmp+t,tmp+t+n);
	 	random_shuffle(tmp,tmp+n);
	}else{
		random_shuffle(tmp,tmp+t);
	} 
    for(int i=0;i<n;i++){
    	system("cls");
		x=tmp[i];
		
    	cout<<i+1<<'/'<<n<<'\n';
    	f.seekg(loc);f>>b>>e>>t;
        
        
        cout<<x<<".";
        //show english
        for(int j=0;j<x;j++)f>>en>>ch;
        cout<<en<<'\n';en.clear();
		//show chinese;
		Stop();
		
		cout<<ch<<'\n';ch.clear();
		Record(x,Stop());
    }
}

void VocsList(){
	
    ifsm f;
    string s;
    int loc=0,t;
    
    f.open(range,std::ios::in);
    
	if(!f){
		cout<<"ERROR\n";
    	return;
    }
    
	f>>t>>t>>t;
	for(int i=1;i<=t;i++){
		s.clear();
		f>>s;cout<<i<<"."<<s;
		for(int j=s.size();j<20;j++)cout<<" ";
		f>>s;cout<<s<<'\n';
	}
	if(lang==0)cout<<"Press any button to continue...\n";
	if(lang==1)cout<<"按下任意鍵繼續...\n";
	Stop();
	 
}

void Email(){
	

	if(lang==0){
		cout<<"If you have any suggestions or problems or you want to donate me\n";
		cout<<"You can use the following E-mail address to contact me\n";
		cout<<"s910466@gapp.ylsh.ilc.edu.tw\n";
		cout<<"W_X_Dai\n";
		cout<<"Pressing any button to continue...";
		Stop();		
	}else if(lang==1){
		cout<<"如果你有任何建議，問題，或是想要資助我們\n";
		cout<<"你可以使用下列的電子郵件跟我聯繫\n";
		cout<<"s910466@gapp.ylsh.ilc.edu.tw\n";
		cout<<"W_X_Dai\n";
		cout<<"按下任意鍵以繼續..."; 
	}
	Stop();

}

void Clear(){
	ofsm f;
	f.open(ranger,std::ios::trunc);
}

void version(){
	if(lang==0){
		cout<<"v1.3.6\n";
		cout<<"version date:2021/11/25\n";
		cout<<"Press any button to continue...\n";
		Stop();
	}else if(lang==1){
		cout<<"v1.3.6\n";
		cout<<"版本日期:2021/11/25\n";
		cout<<"按下任意鍵以繼續...\n";
		Stop();
	}
	
	
}





