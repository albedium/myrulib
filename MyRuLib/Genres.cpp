/////////////////////////////////////////////////////
// Generated By wxActiveRecordGenerator v 1.2.0-rc3
/////////////////////////////////////////////////////

#include "Genres.h"

/** ACTIVE_RECORD **/
Genres::Genres():wxSqliteActiveRecord(){
}

Genres::Genres(const wxString& name,const wxString& server,const wxString& user,const wxString& password,const wxString& table):wxSqliteActiveRecord(name,server,user,password,table){
}

Genres::Genres(DatabaseLayer* database,const wxString& table):wxSqliteActiveRecord(database,table){
}

bool Genres::Create(const wxString& name,const wxString& server,const wxString& user,const wxString& password,const wxString& table){
	return wxSqliteActiveRecord::Create(name,server,user,password,table);
}

GenresRow* Genres::RowFromResult(DatabaseResultSet* result){
	GenresRow* row=new GenresRow(this);
	
	row->GetFromResult(result);
	
	return row;
}

GenresRow* Genres::New(){
	GenresRow* newRow=new GenresRow(this);
	garbageRows.Add(newRow);
	return newRow;
}
bool Genres::Delete(int key){
	try{
		PreparedStatement* pStatement=m_database->PrepareStatement(wxString::Format(wxT("DELETE FROM %s WHERE id_book=?"),m_table.c_str()));
		pStatement->SetParamInt(1,key);
		pStatement->ExecuteUpdate();
		return true;
	}
	catch(DatabaseLayerException& e){
		throw(e);
		return false;
	}
}



GenresRow* Genres::IdBook(int key){
	try{
		PreparedStatement* pStatement=m_database->PrepareStatement(wxString::Format(wxT("SELECT * FROM %s WHERE id_book=?"),m_table.c_str()));
		pStatement->SetParamInt(1,key);
		DatabaseResultSet* result= pStatement->ExecuteQuery();

		result->Next();
		GenresRow* row=RowFromResult(result);
		garbageRows.Add(row);
		m_database->CloseResultSet(result);
		m_database->CloseStatement(pStatement);
		return row;
	}
	catch (DatabaseLayerException& e)
	{
		ProcessException(e);
		return NULL;
	}
}




GenresRow* Genres::Where(const wxString& whereClause){
	try{
		wxString prepStatement = wxString::Format(wxT("SELECT * FROM %s WHERE %s"),m_table.c_str(),whereClause.c_str());
		PreparedStatement* pStatement=m_database->PrepareStatement(prepStatement);
		DatabaseResultSet* result= pStatement->ExecuteQuery();
		
		if(!result->Next())
			return NULL;
		GenresRow* row=RowFromResult(result);
		
		garbageRows.Add(row);
		m_database->CloseResultSet(result);
		m_database->CloseStatement(pStatement);						
		return row;
	}
	catch (DatabaseLayerException& e)
	{
		ProcessException(e);
		return 0;
	}
}

GenresRowSet* Genres::WhereSet(const wxString& whereClause,const wxString& orderBy){
	GenresRowSet* rowSet=new GenresRowSet();
	try{
		wxString prepStatement=wxString::Format(wxT("SELECT * FROM %s WHERE %s"),m_table.c_str(),whereClause.c_str());
		if(!orderBy.IsEmpty())
			prepStatement+=wxT(" ORDER BY ")+orderBy;
		PreparedStatement* pStatement=m_database->PrepareStatement(prepStatement);
		DatabaseResultSet* result= pStatement->ExecuteQuery();
		
		if(result){
			while(result->Next()){
				rowSet->Add(RowFromResult(result));
			}
		}
		
		garbageRowSets.Add(rowSet);
		m_database->CloseResultSet(result);
		m_database->CloseStatement(pStatement);	
		return rowSet;
		
	}
	catch (DatabaseLayerException& e)
	{
		ProcessException(e);
		return 0;
	}
}


GenresRowSet* Genres::All(const wxString& orderBy){
	GenresRowSet* rowSet=new GenresRowSet();
	try{
		wxString prepStatement=wxString::Format(wxT("SELECT * FROM %s"),m_table.c_str());
		if(!orderBy.IsEmpty())
			prepStatement+=wxT(" ORDER BY ")+orderBy;
		PreparedStatement* pStatement=m_database->PrepareStatement(prepStatement);
		
		DatabaseResultSet* result= pStatement->ExecuteQuery();
		
		if(result){
			while(result->Next()){
				rowSet->Add(RowFromResult(result));
			}
		}
		garbageRowSets.Add(rowSet);
		m_database->CloseResultSet(result);
		m_database->CloseStatement(pStatement);	
		return rowSet;
		
	}
	catch (DatabaseLayerException& e)
	{
		ProcessException(e);
		return 0;
	}
}

/** END ACTIVE RECORD **/

/** ACTIVE RECORD ROW **/

GenresRow::GenresRow():wxActiveRecordRow(){
	bool newRow=true;
}

GenresRow::GenresRow(Genres* activeRecord):wxActiveRecordRow(activeRecord){
	bool newRow=true;
}

GenresRow::GenresRow(const GenresRow& src){
	if(&src==this)
		return;
	newRow=src.newRow;
	
	id_genre=src.id_genre;
	id_book=src.id_book;

}

GenresRow::GenresRow(DatabaseLayer* database,const wxString& table):wxActiveRecordRow(database,table){
	newRow=true;
}
	

GenresRow& GenresRow::operator=(const GenresRow& src){
	if(&src==this)
		return *this;
	newRow=src.newRow;
	
	id_genre=src.id_genre;
	id_book=src.id_book;


	return *this;
}

bool GenresRow::GetFromResult(DatabaseResultSet* result){
	
	newRow=false;
		id_genre=result->GetResultString(wxT("id_genre"));
	id_book=result->GetResultInt(wxT("id_book"));


	return true;
}
	

bool GenresRow::Save(){
	try{
		if(newRow){
			PreparedStatement* pStatement=m_database->PrepareStatement(wxString::Format(wxT("INSERT INTO %s (id_genre,id_book) VALUES (?,?)"),m_table.c_str()));
			pStatement->SetParamString(1,id_genre);
			pStatement->SetParamInt(2,id_book);
			pStatement->RunQuery();
			m_database->CloseStatement(pStatement);

			
			newRow=false;
		}
		else{
			PreparedStatement* pStatement=m_database->PrepareStatement(wxString::Format(wxT("UPDATE %s SET id_genre=? WHERE id_book=?"),m_table.c_str()));
			pStatement->SetParamString(1,id_genre);
			pStatement->SetParamInt(2,id_book);
			pStatement->RunQuery();
			m_database->CloseStatement(pStatement);

		}
		
		return true;
	}
	catch (DatabaseLayerException& e)
	{
		wxActiveRecord::ProcessException(e);
		return false;
	}
}

bool GenresRow::Delete(){
	try{
		PreparedStatement* pStatement=m_database->PrepareStatement(wxString::Format(wxT("DELETE FROM %s WHERE id_book=?"),m_table.c_str()));
		pStatement->SetParamInt(1,id_book);
		pStatement->ExecuteUpdate();
		return true;
	}
	catch(DatabaseLayerException& e){
		throw(e);
		return false;
	}
}





/** END ACTIVE RECORD ROW **/

/** ACTIVE RECORD ROW SET **/

GenresRowSet::GenresRowSet():wxActiveRecordRowSet(){
}

GenresRowSet::GenresRowSet(wxActiveRecord* activeRecord):wxActiveRecordRowSet(activeRecord){
}

GenresRowSet::GenresRowSet(DatabaseLayer* database,const wxString& table):wxActiveRecordRowSet(database,table){
}

GenresRow* GenresRowSet::Item(unsigned long item){
	return (GenresRow*)wxActiveRecordRowSet::Item(item);
}


bool GenresRowSet::SaveAll(){
	try{
		m_database->BeginTransaction();
		for(unsigned long i=0;i<Count();i++)
			Item(i)->Save();
		m_database->Commit();
		return true;
	}
	catch (DatabaseLayerException& e)
	{
		m_database->RollBack();
		wxActiveRecord::ProcessException(e);
		return false;
	}
}


int GenresRowSet::CMPFUNC_id_genre(wxActiveRecordRow** item1,wxActiveRecordRow** item2){
	GenresRow** m_item1=(GenresRow**)item1;
	GenresRow** m_item2=(GenresRow**)item2;
	return (*m_item1)->id_genre.Cmp((*m_item2)->id_genre);
}

int GenresRowSet::CMPFUNC_id_book(wxActiveRecordRow** item1,wxActiveRecordRow** item2){
	GenresRow** m_item1=(GenresRow**)item1;
	GenresRow** m_item2=(GenresRow**)item2;
	if((*m_item1)->id_book<(*m_item2)->id_book)
		return -1;
	else if((*m_item1)->id_book>(*m_item2)->id_book)
		return 1;
	else
		return 0;
}

CMPFUNC_proto GenresRowSet::GetCmpFunc(const wxString& var) const{
	if(var==wxT("id_genre"))
		return (CMPFUNC_proto)CMPFUNC_id_genre;
	else if(var==wxT("id_book"))
		return (CMPFUNC_proto)CMPFUNC_id_book;
	else 
	return (CMPFUNC_proto)CMPFUNC_default;
}



/** END ACTIVE RECORD ROW SET **/

////@@begin custom implementations




////@@end custom implementations