/*Malik Hashim Inayat Ullah
BSCS 10-B
CMS : 331944*/

#include <iostream>
#include <fstream>
#include <algorithm>   //For MAX function
#include <string>      //String manupulation
#include <sstream>     //isstringstream Function

#define Buckets 31    //Defining Bucket Size of Hash
using namespace std;   
class Node;            //Forward Addressing
class Movie;
class Hash;


class Movie {               //Movie Class with all column's data
public:
   unsigned int ShowID;           
    string Type;
    string Title;
    string Director;
    string cast;
    string Country;
    int ReleaseYear;
    string Rating;
    string Duration;
    string listedIn;
    string Description;
};


class Hash {             //Hash Class for Hash Table
public:
    struct item {
        Movie* movie;             //Contains Movie Pointer only from the Movie class' Object. Thus less data usage
        item* next;
    };

    item* HashTable[Buckets];          //Creating Hash Pointer
    Hash() {
        for (size_t i = 0; i < Buckets; i++)     //Initializing Hash Table Buckets
        {
            HashTable[i] = new item;
            HashTable[i]->movie = NULL;
            HashTable[i]->next = NULL;

        }
    }

    /// Summary
    /// Does the Insertion to Hash
    /// Receives Movie type pointer and adds that to hash table. 
    /// Genre is the string which is passed and according to genre the Bucket number is assigned
    /// Best Case O(1);  //Omega
    /// Worst Case O(n)

    void AddItem(Movie* object, string genre) {                
        int index = hashval(genre);
        /*cout << "Returned Index: " << index << endl;
        cout << "Object Data" << object->ShowID << endl;*/
        if (HashTable[index]->movie == NULL) {
            HashTable[index]->movie = object;
        }
        else {
            item* ptr = HashTable[index];
            item* newnode = new item;
            newnode->movie = object;
            newnode->next =NULL;

            while (ptr->next != NULL) {
                ptr = ptr->next;
            }
            ptr->next = newnode;


        }
    }
    /// Best Case O(1);  //Omega
    /// Worst Case O(n/m)  while m is the bucket size

    int NoOfItems(int index) {
        int count = 0;
        if (HashTable[index]->movie == NULL)
            return count;
        else {
            count++;
            item* ptr = HashTable[index];
            while (ptr->next != NULL) {
                count++;
                ptr = ptr->next;
            }
        }
        return count;
    }

    void PrintTable() {
        int num;
        for (size_t i = 0; i < Buckets; i++)
        {
            num = NoOfItems(i);
            cout << "<<<<------------------------------------------------------------------------------->>>>" << endl;
            cout << "Index: " << i << endl;
            cout << "Number of Items at Index (" << i << ") are : "<< num<< endl;
            if (HashTable[i]->movie != NULL) {
             
             cout << "<<<<------------------------------------------------------------------------------->>>>" << endl;
             cout << "---> SHOW ID: " << HashTable[i]->movie->ShowID << "|" << endl << endl;
             cout << "-------------------------------------------------------------------------------" << endl;

             cout << "---> TITLE: " << HashTable[i]->movie->Title << "|" << endl << endl;
             cout << "-------------------------------------------------------------------------------" << endl;

             cout << "---> TYPE: " << HashTable[i]->movie->Type << "|" << endl << endl;
             cout << "-------------------------------------------------------------------------------" << endl;

             cout << "---> RATING : " << HashTable[i]->movie->Rating << "|" << endl << endl;
             cout << "-------------------------------------------------------------------------------" << endl;
             cout << "---> LISTED IN : " << HashTable[i]->movie->listedIn << "|" << endl << endl;
             cout << "-------------------------------------------------------------------------------" << endl;
             cout << "---> DURATION : " << HashTable[i]->movie->Duration << "|" << endl << endl;
             cout << "-------------------------------------------------------------------------------" << endl;

             cout << "---> DIRECTOR : " << HashTable[i]->movie->Director << "|" << endl << endl;
             cout << "-------------------------------------------------------------------------------" << endl;

             cout << "---> COUNTRY : " << HashTable[i]->movie->Country << "|" << endl << endl;
             cout << "-------------------------------------------------------------------------------" << endl;

             cout << "---> CAST : " << HashTable[i]->movie->cast << "|" << endl << endl;
             cout << "-------------------------------------------------------------------------------" << endl;

             cout << "---> RELEASE YEAR : " << HashTable[i]->movie->ReleaseYear << "|" << endl << endl;
             cout << "-------------------------------------------------------------------------------" << endl;
             cout << "---> DECRIPTION :" << HashTable[i]->movie->Description << "|" << endl << endl;
            
             cout << "----------------------------------DATA COMPLETE FOR ENTRY---------------------------------------------" << endl << endl;


            }
        }
    }

    /// Best Case O(1);
    /// Worst Case O(l); lenght of string

    int hashval(string alpha) {
        unsigned int weight = 0; int g = 31;
        for (size_t i = 0; i < alpha.length(); i++)     //Calculates Teh ASCII of Each Character then returns the weight
                                                        //After Sum
        {
            if((int)alpha[i]!= ' ')
            weight = (weight*g) + (int)alpha[i];
        }
       // cout << "VALLLLLLLLLLL" << weight % Buckets;
        return weight%Buckets;
    }
   
    /// Best Case O(1);
    /// Worst Case O(n/m);
   
    void PrintItemsIndex(int index) {         //Moves through Index of Hashtable
        if (HashTable[index]->movie == NULL) {
            cout << "Index has nothing in it!" << endl;
         cout <<endl<< "----------------------------------------------------------------------------------------------------" << endl << endl;
        }
        else {
            item* ptr = HashTable[index];
            while(ptr != NULL)
            {
                //cout <<endl<< "-------------------------------------------------------------------------------" << endl << endl;
                cout << "---> SHOW ID: " << ptr->movie->ShowID <<"|"<< endl << endl;
                cout << "-------------------------------------------------------------------------------" << endl;

                cout << "---> TITLE: " << ptr->movie->Title << "|" << endl << endl;
                cout << "-------------------------------------------------------------------------------" << endl;

                cout << "---> TYPE: " << ptr->movie->Type << "|" << endl << endl;
                cout << "-------------------------------------------------------------------------------" << endl;

                cout << "---> RATING : " << ptr->movie->Rating << "|" << endl << endl;
                cout << "-------------------------------------------------------------------------------" << endl;
                cout << "---> LISTED IN : " << ptr->movie->listedIn << "|" << endl << endl;
                cout << "-------------------------------------------------------------------------------" << endl;
                cout << "---> DURATION : " << ptr->movie->Duration << "|" << endl << endl;
                cout << "-------------------------------------------------------------------------------" << endl;

                cout << "---> DIRECTOR : " << ptr->movie->Director << "|" << endl << endl;
                cout << "-------------------------------------------------------------------------------" << endl;

                cout << "---> COUNTRY : " << ptr->movie->Country << "|" << endl << endl;
                cout << "-------------------------------------------------------------------------------" << endl;

                cout << "---> CAST : " << ptr->movie->cast << "|" << endl << endl;
                cout << "-------------------------------------------------------------------------------" << endl;

                cout << "---> RELEASE YEAR : " << ptr->movie->ReleaseYear << "|" << endl << endl;
                cout << "-------------------------------------------------------------------------------" << endl;
                cout << "---> DECRIPTION :" << ptr->movie->Description << "|" << endl << endl;
                ptr = ptr->next;
                cout << "----------------------------------DATA COMPLETE FOR ENTRY---------------------------------------------" << endl<<endl;

            } 
        }
    }
    
    
   
    /// Best Case O(1);
    /// Worst Case O(n/m); For Searching Included
    void Search_By_Genre(string genre) {
     //   if (genre == "Action" || genre == "Children" || genre == "Comedies" || genre == "Adventure" || genre== "International Movies") {
            int index = hashval(genre);
            PrintItemsIndex(index);
       // }
    }

};

class Node {                      //Node Class creates the object of Movie automatically.
public:
    int height;                   //Attributes for a AVL Tree
    Movie value;
    Node* right;
    Node* left;

    //struct AVL_ByYear {
    //    Movie* year;
    //    Node* right;
    //    Node* Left;
    //};

    //AVL_ByYear* Year;

    //This function takes Node, Movie object as temp data storage for each line
    //Hash object to store into HAsh with described Genre



    Node* ReadDataToTree(Node* nn, Movie object,Hash* hash) {   
      /*  Movie* ptr = new Movie;
        ptr = &object;*/
        ifstream  Netflix("netflix.csv", ios::in);    //Reading data from CSV
        if (Netflix.is_open()) {
            int count = 0, alpha;
            string line;
            while (Netflix.good()) {    //Until Good /END
                Node* store = new Node;
                //Getting Each Attribute and storing to respective Object part.
            getline(Netflix, line, ',');
            alpha = atoi(line.c_str());
            object.ShowID = alpha;
            getline(Netflix, object.Type, ',');
            getline(Netflix, object.Title, ',');
            getline(Netflix, object.Director, ',');
            getline(Netflix, object.cast, ',');
            getline(Netflix, object.Country, ',');
            getline(Netflix, line, ',');
            alpha = atoi(line.c_str());
            object.ReleaseYear = alpha;
            getline(Netflix, object.Rating, ',');
            getline(Netflix, object.Duration, ',');
            getline(Netflix, object.listedIn, ',');
            //-------------------------------------------------------------------------------
             int count = 0;
             //Calculation of Bars "|" that are in the database for Genre Seperation
            for (int i = 0; object.listedIn[i] != '\0'; i++) {
                if (object.listedIn [i] == '|')// this condition is used to avoid counting space
                {
                    count++;
                }
            }
           //Then Dynamic Array to store the specific Number of Genre
           string* array_ = new string[count+1];
           // string array_[3];
            if (count != 0) {
             //   cout << "count: " << count<<endl;
                Array_manup(object.listedIn, array_, count);   //Manupulates Array and store data to it

            }
            
            getline(Netflix, object.Description, '\n');

           
            
            nn=nn->InsertAVL(nn, object,store);  //Storing to AVL TRee and Store object for the location to the Newly inserted node
         
          
            //  cout << store->value.ShowID << endl;
            if(count==0)
             hash->AddItem(&(store->value), object.listedIn);  //Passes the address to that node.
            else
            {
                for (size_t i = 0; i < count + 1; i++)
                {
                    hash->AddItem(&(store->value), array_[i]);   //If Multiple Categories
                }
            }
        }
            Netflix.close();
            


        }
        return nn;
    }

    void Array_manup(string obj, string  *&array_,int pipe) {
     
        istringstream is(obj); //Creating istring object for getline
           for (size_t i = 0; i < pipe+1; i++)
           {
               if (i < pipe) {
                   getline(is, array_[i], '|');  //Seperates String by "|"
                   
               }
              if(i==pipe)
               getline(is, array_[i], '\0');

           }


           /*for (size_t i = 0; i < pipe+1; i++)
           {
               cout << "Array : " << array_[i] << endl;

           }*/
    }

    Node* newnode(Movie value) {       //Newnode Creation Function.
        Node* nn = new Node;
        nn->value = value;
        nn->height = 1;
        return (nn);
    }

    int GetHeight(Node* newnode) {   //Gets Height of a Node
        if (newnode == NULL)
            return 0;
        return newnode->height;
    }


    int Balance_Factor(Node* nn) {  //Checks for balance of AVL tree
        if (nn == NULL)
            return 0;
        return (GetHeight(nn->right) - GetHeight(nn->left));
    }

    Node* RightRotation(Node* alpha) {   // rotates to right
        Node* Beta = alpha->left;
        Node* Gamma = Beta->right;

        //Proceeding Rotation

        alpha->left = Gamma;
        Beta->right = alpha;

        // Height is to updated due to rotation

        alpha->height = max(GetHeight(alpha->right), GetHeight(alpha->left)) + 1;
        Beta->height = max(GetHeight(Beta->right), GetHeight(Beta->left)) + 1;

        return (Beta);
    }

    Node* LeftRotation(Node* Beta) {  // rotates to left
        Node* Alpha = Beta->right;
        Node* Gamma = Alpha->left;

        Beta->right = Gamma;
        Alpha->left = Beta;

        Alpha->height = max(GetHeight(Alpha->right), GetHeight(Alpha->left)) + 1;
        Beta->height = max(GetHeight(Beta->right), GetHeight(Beta->left)) + 1;
        return (Alpha);
    }


    Node* InsertAVL(Node* nn, Movie value,Node* &store) {    //Insertion to AVL with Balance Check
        if (nn == NULL) {
            store = newnode(value);    //Storing newly inserted
           // cout << "AVL"<<store->value.ShowID << endl;
            return (newnode(value));
        }
        else if (value.Title > nn->value.Title)     //Creating Tree based on Title Ascending
            nn->right = InsertAVL(nn->right, value,store);
        else
            nn->left = InsertAVL(nn->left, value,store);

        return nn;

        //Updating Height

        nn->height = max(GetHeight(nn->right), GetHeight(nn->left)) + 1;

        //After this a check for balance of tree using the Balance Factor.
        int balanceofAVL = Balance_Factor(nn);    

        //If Unblanaced AVL
        if (balanceofAVL > 1 && value.Title < (nn->left)->value.Title)   //LL- Rotation
            return RightRotation(nn);
        if (balanceofAVL <-1 && value.Title >(nn->right)->value.Title)   //RR- Rotation
            return LeftRotation(nn);
        if (balanceofAVL > 1 && value.Title > (nn->left)->value.Title) {   //LR- Rotation
            nn->left = LeftRotation(nn->left);
            return RightRotation(nn);
        }
        if (balanceofAVL < -1 && value.Title < (nn->right)->value.Title) {   //RL- Rotation
            nn->right = RightRotation(nn->right);
            return LeftRotation(nn);
        }

        return nn;
    }

    void InOrder(Node* root)    //InOrder Alphabatic Print of Tree
    { 
        if (root != NULL)
        {
            InOrder(root->left);
            
            cout << "<<<<------------------------------------------------------------------------------->>>>" << endl;

            cout << "---> SHOW ID: " << root->value.ShowID << "|" << endl << endl;
            cout << "-------------------------------------------------------------------------------" << endl;

            cout << "---> TITLE: " << root->value.Title << "|" << endl << endl;
            cout << "-------------------------------------------------------------------------------" << endl;

            cout << "---> TYPE: " << root->value.Type << "|" << endl << endl;
            cout << "-------------------------------------------------------------------------------" << endl;

            cout << "---> RATING : " << root->value.Rating << "|" << endl << endl;
            cout << "-------------------------------------------------------------------------------" << endl;
            cout << "---> LISTED IN : " << root->value.listedIn << "|" << endl << endl;
            cout << "-------------------------------------------------------------------------------" << endl;
            cout << "---> DURATION : " << root->value.Duration << "|" << endl << endl;
            cout << "-------------------------------------------------------------------------------" << endl;

            cout << "---> DIRECTOR : " << root->value.Director << "|" << endl << endl;
            cout << "-------------------------------------------------------------------------------" << endl;

            cout << "---> COUNTRY : " << root->value.Country << "|" << endl << endl;
            cout << "-------------------------------------------------------------------------------" << endl;

            cout << "---> CAST : " << root->value.cast << "|" << endl << endl;
            cout << "-------------------------------------------------------------------------------" << endl;

            cout << "---> RELEASE YEAR : " << root->value.ReleaseYear << "|" << endl << endl;
            cout << "-------------------------------------------------------------------------------" << endl;
            cout << "---> DECRIPTION :" << root->value.Description << "|" << endl << endl;
            cout << "----------------------------------DATA COMPLETE FOR ENTRY---------------------------------------------" << endl << endl;
            InOrder(root->right);
        }
        

    }

    /*Node* recursiveSearch(Node* tempo, int object) {
    * Node* temp=tempo;
        cout << "The Node is : " << temp->value.ShowID << endl;
        if (temp == NULL || temp->value.ReleaseYear == object) {
            cout << "The Movie Name is: " << (temp)->value.Title << endl;
            return temp;
        }
        else if (temp->value.ReleaseYear < object)
            return recursiveSearch(temp->left, object);

        else
            return recursiveSearch(temp->right, object);
    }*/

    /// Best Case O(1);
    /// Worst Case  O(logn);
    Node * SearchName(Node* root,string name) {       //Search by Name function Recieves Node and String name
    if (root == NULL) {
      return root;
    } else {
      Node * temp = root;  //Creating Temp Node for traversal.
      while (temp != NULL) {
        if (name == temp -> value.Title) {
            //cout << "The Movie Name is: " << (temp)->value.Title << endl;
            cout << "---> SHOW ID: " << temp->value.ShowID << "|" << endl << endl;
            cout << "-------------------------------------------------------------------------------" << endl;

            cout << "---> TITLE: " << temp->value.Title << "|" << endl << endl;
            cout << "-------------------------------------------------------------------------------" << endl;

            cout << "---> TYPE: " << temp->value.Type << "|" << endl << endl;
            cout << "-------------------------------------------------------------------------------" << endl;

            cout << "---> RATING : " << temp->value.Rating << "|" << endl << endl;
            cout << "-------------------------------------------------------------------------------" << endl;
            cout << "---> LISTED IN : " << temp->value.listedIn << "|" << endl << endl;
            cout << "-------------------------------------------------------------------------------" << endl;
            cout << "---> DURATION : " << temp->value.Duration << "|" << endl << endl;
            cout << "-------------------------------------------------------------------------------" << endl;

            cout << "---> DIRECTOR : " << temp->value.Director << "|" << endl << endl;
            cout << "-------------------------------------------------------------------------------" << endl;

            cout << "---> COUNTRY : " << temp->value.Country << "|" << endl << endl;
            cout << "-------------------------------------------------------------------------------" << endl;

            cout << "---> CAST : " << temp->value.cast << "|" << endl << endl;
            cout << "-------------------------------------------------------------------------------" << endl;

            cout << "---> RELEASE YEAR : " << temp->value.ReleaseYear << "|" << endl << endl;
            cout << "-------------------------------------------------------------------------------" << endl;
            cout << "---> DECRIPTION :" << temp->value.Description << "|" << endl << endl;
            cout << "----------------------------------DATA COMPLETE FOR ENTRY---------------------------------------------" << endl << endl;
          return temp;
        } else if (name < temp -> value.Title) {
          temp = temp -> left;
        } else {
          temp = temp -> right;
        }
      }
      return NULL;
    }
  }
    
};


int main()
{
 
    //Delaring Class Objecys for usage
    Hash* Hashii=new Hash;
    Node* newnode = NULL;
    Node* newnodee = NULL;
    Node* storage = new Node;
    Movie temp;
    Movie object;
    //Menu for Selection
    cout << "|-----------------------------------MENU---------------------------------|" << endl << endl;
    int choice=0;
    while(choice!=-1){
        int index;
        cout << endl << endl;
        cout << "---> 1. Read Data To AVL Tree & Hash Table     " << endl;
        cout << "---> 2. Complete Movie List in Alphabetical Order " << endl;
        cout << "---> 3. Search Movie By Genre " << endl;
        cout << "---> 4. Search Movie By Name " << endl;
        cout << "---> 5. Number of Total Index and Data in each Hash Table" << endl;
        cout << "---> 6. Return Data of Specific Index of Hash Table" << endl;
        cout << "---> 7. Insert A Movie AVL + Hash " << endl;
        cout << "---> 8. Insert A Movie into Hash by Genre " << endl;
        string genre, movie_name, insert;
        cout <<endl<< "---> Enter Choice :   "; cin >> choice;
        switch (choice)
        {
        case 1:
            newnode = newnode->ReadDataToTree(newnode, object, Hashii);
            break;
        case 2:
            newnode->InOrder(newnode);
            break;
        case 3:
            cin.ignore();
            cout << "---> Enter Genre : "; getline(cin, genre);
            Hashii->Search_By_Genre(genre);  cin.ignore();
            break;
        case 4:
            cin.ignore();
            cout << "---> Enter Movie Name : "; getline( cin,movie_name);
            newnodee=newnode->SearchName(newnode,movie_name);
            break;
        case 5:
            Hashii->PrintTable();
            break;
        case 6:
            cout << "---> Enter Index of Hash Table : "; cin >> index;
            Hashii->PrintItemsIndex(index);
            break;
        case 7:
            cout << "---> SHOW ID: "; cin >> temp.ShowID;               cin.ignore();
            cout << "-------------------------------------------------------------------------------" << endl;

            cout << "---> TITLE: "; getline(cin, temp.Title);           cin.ignore();
            cout << "-------------------------------------------------------------------------------" << endl;
                                                                        
            cout << "---> TYPE: "; getline(cin, temp.Type);             cin.ignore();
            cout << "-------------------------------------------------------------------------------" << endl;
                                                                        
            cout << "---> RATING : "; getline(cin,temp.Rating);         cin.ignore();
            cout << "-------------------------------------------------------------------------------" << endl;
            cout << "---> Genre : "; getline(cin,temp.listedIn);    cin.ignore();
            cout << "-------------------------------------------------------------------------------" << endl;
            cout << "---> DURATION : "; getline(cin,temp.Duration);     cin.ignore();
            cout << "-------------------------------------------------------------------------------" << endl;
                                                                        
            cout << "---> DIRECTOR : "; getline(cin,temp.Director);     cin.ignore();
            cout << "-------------------------------------------------------------------------------" << endl;
                                                                        
            cout << "---> COUNTRY : "; getline(cin,temp.Country);       cin.ignore();
            cout << "-------------------------------------------------------------------------------" << endl;
                                                                        
            cout << "---> CAST : "; getline(cin,temp.cast);             cin.ignore();
            cout << "-------------------------------------------------------------------------------" << endl;
                                                                        
            cout << "---> RELEASE YEAR : "; cin >> temp.ReleaseYear;    cin.ignore();
            cout << "-------------------------------------------------------------------------------" << endl;
            cout << "---> DECRIPTION :"; getline(cin ,temp.Description);//cin.ignore();
            cout << "----------------------------------DATA COMPLETE FOR ENTRY---------------------------------------------" << endl << endl;
            newnode = newnode->InsertAVL(newnode, temp, storage); 
            Hashii->AddItem(&(storage->value), temp.listedIn);         
           // newnode_->InsertAVL()
           
            break;
        case 8:
            cin.ignore();
            cout << "---> Genre : "; getline(cin, temp.listedIn);    cin.ignore();
            cout << "---> SHOW ID: "; cin >> temp.ShowID;               cin.ignore();
            cout << "-------------------------------------------------------------------------------" << endl;

            cout << "---> TITLE: "; getline(cin, temp.Title);           cin.ignore();
            cout << "-------------------------------------------------------------------------------" << endl;

            cout << "---> TYPE: "; getline(cin, temp.Type);             cin.ignore();
            cout << "-------------------------------------------------------------------------------" << endl;

            cout << "---> RATING : "; getline(cin, temp.Rating);         cin.ignore();
            cout << "-------------------------------------------------------------------------------" << endl;
            
            cout << "-------------------------------------------------------------------------------" << endl;
            cout << "---> DURATION : "; getline(cin, temp.Duration);     cin.ignore();
            cout << "-------------------------------------------------------------------------------" << endl;

            cout << "---> DIRECTOR : "; getline(cin, temp.Director);     cin.ignore();
            cout << "-------------------------------------------------------------------------------" << endl;

            cout << "---> COUNTRY : "; getline(cin, temp.Country);       cin.ignore();
            cout << "-------------------------------------------------------------------------------" << endl;

            cout << "---> CAST : "; getline(cin, temp.cast);             cin.ignore();
            cout << "-------------------------------------------------------------------------------" << endl;

            cout << "---> RELEASE YEAR : "; cin >> temp.ReleaseYear;    cin.ignore();
            cout << "-------------------------------------------------------------------------------" << endl;
            cout << "---> DECRIPTION :"; getline(cin, temp.Description);//cin.ignore();
            cout << "----------------------------------DATA COMPLETE FOR ENTRY---------------------------------------------" << endl << endl;
            newnode = newnode->InsertAVL(newnode, temp, storage);
            Hashii->AddItem(&(storage->value), temp.listedIn);
            break;
        }


        }

    return 0;


}


